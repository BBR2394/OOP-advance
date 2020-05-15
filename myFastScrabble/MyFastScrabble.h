#ifndef MYFASTSCRABBLE_H_
# define MYFASTSCRABBLE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <deque>
#include <set>

class MyFastScrabble
{
public:
	MyFastScrabble();
	~MyFastScrabble();

private:
	//int 	_c;
	std::list<std::string> _saveMydico;
	std::list<std::string> mydico;
	std::list<std::string> _dicoAccordingAnagram;
	std::list<std::string> _dicoaccordingExactLetterAndAnagram;
	std::list<std::string> _dicoWithEqualNumOfChar;
	//std::deque<std::string> mydico;
	std::string 	_anagram;
	std::ifstream _myfile;
	std::set<char>	_anagramSet;
	std::multiset<char>	_anagramMultiSet;
	char setLowerCase(char c);

public:
	int initAnagram(std::string);
	void printAnagram();
	void shrinkDico();
	int addWordInDico(std::string );
	int openFile(std::string);
	int storeDico();
	void closeFile();
	void printDico();
	void printShrinkDico();
	void printThirdDico();
	int getSizeShrinkDico() const;

	void updateDico();

	int printResultat();

	int findIfWordContainOtherChar();

	int findIfWordContainOnlySameAmountOfLetter();
	void printFourthDico();
};

#endif