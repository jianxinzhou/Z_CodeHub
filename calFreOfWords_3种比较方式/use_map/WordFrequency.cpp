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
        stopList_.insert(word);

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
        if(stopList_.count(word) == 0)
        	words_[word]++;
    }

    infile.close();
}

void WordFrequency::copyWordsToVector()
{
	sortWords_.clear();
	//back_inserter(sortWords_) 插入迭代器
	//front_inserter
	copy(words_.begin(), words_.end(), back_inserter(sortWords_));
}

void WordFrequency::sortWordsByFrequency()
{

	sort(sortWords_.begin(), sortWords_.end(), util::cmpWord);
}

void WordFrequency::printWordFrequency() const
{
	for(vector<pair<string, int> >::const_iterator it = sortWords_.begin(); 
        it != sortWords_.end(); 
        ++it)
    {
        printf("word :%s, frequency: %d\n", it->first.c_str(), it->second);
    }
}

