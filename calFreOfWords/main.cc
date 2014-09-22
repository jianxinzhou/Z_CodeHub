#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 
#endif  /*__STDC_FORMAT_MACROS*/
#include <inttypes.h>
using namespace std;

struct Word
{
    string word_;
    int count_;
};

int64_t getUTime(); //微秒
void readStopList(ifstream &in, vector<string> &stop);
void readFile(ifstream &in, vector<Word> &words, const vector<string> &stop);
void earsePunct(string &word);
void stringToLower(string &word);
bool isStopWord(const string &word, const vector<string> &stop);
void addWordToDict(vector<Word> &words, const string &word);
void sortWordFrequency(vector<Word> &words);
static bool cmp(const Word &w1, const Word &w2);
void printWordFrequency(const vector<Word> &words);

int main(int argc, const char *argv[])   // ./a.out 要统计词频的文件名
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage:%s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ifstream infile(argv[1]);
    if(!infile)
        throw runtime_error("open file error!");

    ifstream stopfile("stopList.txt");
    if(!stopfile)
        throw runtime_error("stopList doesn't exsit!");

    int64_t startTime = getUTime();

    /* 从停用词文件中读取停用词 */
    vector<string> stop;
    readStopList(stopfile, stop);

    /* 从目标文件中读取单词 */
    vector<Word> words;
    readFile(infile, words, stop);

    int64_t middleTime = getUTime();
    
    /* 根据词频排序*/
    sortWordFrequency(words);

    int64_t endTime = getUTime();

    /* 打印词频 */
    printWordFrequency(words);

    int64_t costByReading = middleTime - startTime;
    int64_t costBySort = endTime - middleTime;

    printf("读取文件花费的时间：%" PRId64 "\n排序所花费的时间：%" PRId64 "\n", costBySort / 1000, costBySort);

    return 0;
}

int64_t getUTime()
{
    struct timeval tv;
    ::memset(&tv, 0, sizeof tv);
    if(::gettimeofday(&tv, NULL) == -1)
    {
        throw runtime_error("fail to get time of day!");
    }
    int64_t t = tv.tv_usec;
    t += tv.tv_sec * 1000 * 1000;
    return t;
}

void readStopList(ifstream &in, vector<string> &stop)
{
    stop.clear();
    string word;
    while(in >> word)
    {
        stop.push_back(word);
    }
}

void readFile(ifstream &in, 
              vector<Word> &words, 
              const vector<string> &stop)
{
    words.clear();
    string word;
    while(in >> word)
    {
        earsePunct(word);
        stringToLower(word);
        if(!isStopWord(word,stop))
        {
            addWordToDict(words, word);
        }
    }
}

void earsePunct(string &word)
{
    string::iterator it = word.begin();
    while(it != word.end())
    {
        if(ispunct(*it))
        {
            it = word.erase(it);
        }else
        {
            ++it;
        }
    }
}

void stringToLower(string &word)
{
    for(string::iterator it = word.begin();
        it != word.end();
        ++it)
    {
        if(isupper(*it))
        {
            *it = tolower(*it);
        }
    }
}

bool isStopWord(const string &word, const vector<string> &stop)
{
    vector<string>::const_iterator it =
        find(stop.begin(), stop.end(), word);
    return (it != stop.end());
}

void addWordToDict(vector<Word> &words, const string &word)
{
    vector<Word>::iterator it = words.begin();
    while(it != words.end())
    {
        if(word == it->word_)
        {
            ++ it->count_;
            break;
        }
        ++it;
    }
    if(it == words.end())
    {
        Word tmp = {word,1};
        words.push_back(tmp);
    }
}

void sortWordFrequency(vector<Word> &words)
{
     sort(words.begin(), words.end(), cmp);
}

static bool cmp(const Word &w1, const Word &w2)
{
    return w1.count_ > w2.count_;
}

void printWordFrequency(const vector<Word> &words)
{
    for(vector<Word>::const_iterator it = words.begin();
        it != words.end();
        ++it)
    {
        fprintf(stdout, "word : %s, frequency: %d\n", it->word_.c_str(), it->count_);
    }
}
