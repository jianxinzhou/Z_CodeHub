#ifndef WORD_FREQUENCY_H
#define WORD_FREQUENCY_H

#include <vector>
#include <string>
#include <utility>

class WordFrequency
{
public:
	WordFrequency(const std::string &filename, const std::string &stopFile);

	void readStopList();
	void readWordFile();

	void sortWordsByFrequency();
	void printWordFrequency() const;

private:
	void addWordToDict(const std::string &word);
	bool isStopWord(const std::string &word) const;

	typedef std::vector<std::pair<std::string, int> >::iterator WordIt;
	typedef std::vector<std::pair<std::string, int> >::const_iterator WordKIt;

	std::string filename_;
	std::string stopFile_;

	std::vector<std::pair<std::string, int> > words_;
	std::vector<std::string> stopList_;
};


#endif /* WORD_FREQUENCY_H */