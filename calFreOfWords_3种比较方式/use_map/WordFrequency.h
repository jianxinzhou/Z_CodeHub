#ifndef WORD_FREQUENCY_H
#define WORD_FREQUENCY_H

#include <vector>
#include <string>
#include <map>
#include <set>

class WordFrequency
{
public:
	WordFrequency(const std::string &filename, const std::string &stopFile);

	void readStopList();
	void readWordFile();

	void copyWordsToVector();
	void sortWordsByFrequency();
	void printWordFrequency() const;

private:

	typedef std::map<std::string, int>::iterator WordIt;
	typedef std::map<std::string, int>::const_iterator WordKIt;

	std::string filename_;
	std::string stopFile_;

	std::map<std::string, int> words_;
	std::set<std::string> stopList_;

	std::vector<std::pair<std::string, int> > sortWords_;
};


#endif /* WORD_FREQUENCY_H */