#include "WordFrequency.h"
#include "StringUtil.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace stringutil;

namespace util
{
bool cmpWord(const pair<string, int> &w1, const pair<string, int> &w2)
{
    //a > b
    return w1.second > w2.second;
}
}


WordFrequency::WordFrequency(const std::string &filename, 
							 const std::string &stopFile)
	:filename_(filename),
	 stopFile_(stopFile)
{	
}

void WordFrequency::readStopList()
{
	ifstream infile(stopFile_.c_str());
	if(!infile)
		throw runtime_error("stopList打开失败");

	string word;
    while(infile >> word)
        stopList_.push_back(word);

    infile.close();
}

void WordFrequency::readWordFile()
{
	ifstream infile(filename_.c_str());
	if(!infile)
		throw runtime_error("word文件打开失败");

	words_.clear();
    string word;
    while(infile >> word)
    {
        erasePunct(word);
        if(isAllDigit(word))
        	continue;
        stringToLower(word);
        if(!isStopWord(word))
            addWordToDict(word);
    }

    infile.close();
}


void WordFrequency::addWordToDict(const std::string &word)
{
	WordIt it = words_.begin();
	for(; it != words_.end(); ++it)
	{
		if(word == it->first)
		{
			++it->second;
			break;
		}
	}

	if(it == words_.end())
	{
		words_.push_back(make_pair(word, 1));
	}
}




void WordFrequency::sortWordsByFrequency()
{
	sort(words_.begin(), words_.end(), util::cmpWord);
}

void WordFrequency::printWordFrequency() const
{
	for(WordKIt it = words_.begin(); 
        it != words_.end(); 
        ++it)
    {
        printf("word :%s, frequency: %d\n", it->first.c_str(), it->second);
    }
}

bool WordFrequency::isStopWord(const std::string &word) const
{
	vector<string>::const_iterator it = 
        find(stopList_.begin(), stopList_.end(), word);
    return (it != stopList_.end());
}
