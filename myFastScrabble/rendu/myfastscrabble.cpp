/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-01 14:56:56
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-08 11:28:15
*/


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
	std::list<std::string> _saveMydico;
	std::list<std::string> mydico;
	std::list<std::string> _dicoAccordingAnagram;
	std::list<std::string> _dicoaccordingExactLetterAndAnagram;
	std::list<std::string> _dicoWithEqualNumOfChar;
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

MyFastScrabble::MyFastScrabble()
{

}

MyFastScrabble::~MyFastScrabble()
{

}

char MyFastScrabble::setLowerCase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

int MyFastScrabble::initAnagram(std::string anagram)
{
	_anagram = anagram;
	for (long unsigned int i = 0; i < anagram.size(); i++)
	{
		_anagramSet.insert(setLowerCase(anagram[i]));
		_anagramMultiSet.insert(setLowerCase(anagram[i]));
	}
	return 0;
}

void MyFastScrabble::printAnagram()
{
	int c = 0;
	std::set<char>::iterator it = _anagramSet.begin();
	while (it != _anagramSet.end())
	{
		std::cout << "letter anagram n°" << c << " : " << *it << std::endl;
		it++;
		c++;
	}
}

int MyFastScrabble::addWordInDico(std::string newWord)
{
	mydico.push_back(newWord);
	_saveMydico.push_back(newWord);
	return 0;
}

/* reset le dico de base depuis la sauvegarde */
/* ici on RESET */
void MyFastScrabble::updateDico()
{
	mydico = _saveMydico;
	_anagramSet.clear();
	_anagramMultiSet.clear();
	_dicoWithEqualNumOfChar.clear();
}

/* shrink according tot the size */
void MyFastScrabble::shrinkDico()
{
	std::string word;
	while (mydico.size() > 0)
	{
		word = mydico.front();
		if (word.size() == _anagram.size())
			_dicoAccordingAnagram.push_back(word);
		mydico.pop_front();
	}
}

int MyFastScrabble::findIfWordContainOtherChar()
{
	std::string word;
	std::string wordSave;
	char 	ch = '\0';
	while (_dicoAccordingAnagram.size() > 0)
	{
		word = _dicoAccordingAnagram.front();
		wordSave = word;
		while (word.size() > 0) {
			ch = word.back();
			ch = setLowerCase(ch);
			if (_anagramSet.find(ch) == _anagramSet.end())
				break;
			else {
				word.pop_back();
			}
		}
		if (word.size() == 0){
				_dicoaccordingExactLetterAndAnagram.push_back(wordSave);
			}
		_dicoAccordingAnagram.pop_front();
	}
	return 0;
}
//third dico to pop : _dicoaccordingExactLetterAndAnagram
//fourth to create : _dicoWithEqualNumOfChar
int MyFastScrabble::findIfWordContainOnlySameAmountOfLetter()
{
	std::string word;
	std::string wordSave;
	std::multiset<char> wordMSet;
	int cOne = 0;
	int cTwo = 0;
	std::set<char>::iterator itSet = _anagramSet.begin();

	while (_dicoaccordingExactLetterAndAnagram.size() > 0)
	{
		word = _dicoaccordingExactLetterAndAnagram.front();
		wordSave = word;
		while (word.size() > 0)
		{
			wordMSet.insert(setLowerCase(word.back()));
			word.pop_back();
		}
		while (itSet != _anagramSet.end())
		{
			cOne = _anagramMultiSet.count(*itSet);
			cTwo = wordMSet.count(*itSet);
			if (cOne != cTwo)
				break;
			itSet++;
		}
		if (itSet == _anagramSet.end()){
			_dicoWithEqualNumOfChar.push_back(wordSave);
		}
		itSet = _anagramSet.begin();
		wordMSet.clear();
		_dicoaccordingExactLetterAndAnagram.pop_front();
	}
	return 0;
}

//_dicoWithEqualNumOfChar
void MyFastScrabble::printFourthDico() 
{
	int c = 0;
	std::list<std::string>::iterator it = _dicoWithEqualNumOfChar.begin();
	while (it != _dicoWithEqualNumOfChar.end())
	{
		std::cout << "Fourth dico: word n°" << c << " : " << *it << std::endl;
		it++;
		c++;
	}
}

char set_lower_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

bool my_comparaison_function(const std::string& first, const std::string& second)
{
	int i = 0;
	char a = 0;
	char b = 0;
	while (i < first.length() && i < second.length())
	{
		a = set_lower_case(first[i]);
		b = set_lower_case(second[i]);
		if (a < b)
			return true;
		else if (a > b)
			return false;
		i++;
	}
	return first.length() < second.length();
}

int MyFastScrabble::printResultat()
{
	int c = 0;
	//ajouter un sort
	//_dicoWithEqualNumOfChar.sort(my_comparaison_function);
	_dicoWithEqualNumOfChar.sort();
	std::list<std::string>::iterator it = _dicoWithEqualNumOfChar.begin();
	if (_dicoWithEqualNumOfChar.size() <=0 )
		return 1;
	while (it != _dicoWithEqualNumOfChar.end())
	{
		std::cout << *it << std::endl;
		it++;
		c++;
	}
	return 0;
}

void MyFastScrabble::printThirdDico() 
{
	int c = 0;
	std::list<std::string>::iterator it = _dicoaccordingExactLetterAndAnagram.begin();
	while (it != _dicoaccordingExactLetterAndAnagram.end())
	{
		std::cout << "Third dico: word n°" << c << " : " << *it << std::endl;
		it++;
		c++;
	}
}

void MyFastScrabble::printShrinkDico()
{
	int c = 0;
	std::list<std::string>::iterator it=_dicoAccordingAnagram.begin();
	while (it != _dicoAccordingAnagram.end())
	{
		std::cout << "word n°" << c << " : " << *it << std::endl;
		it++;
		c++;
	}
}

void MyFastScrabble::printDico()
{
	int c = 0;
	std::list<std::string>::iterator it=mydico.begin();
	while (it != mydico.end())
	{
		std::cout << "word n°" << c << " : " << *it << std::endl;
		it++;
		c++;
	}
}

int MyFastScrabble::openFile(std::string filename)
{
	_myfile.open(filename);
	if (!_myfile.is_open())
	{
		//std::cout << "\x1B[106m\x1B[35m\x1B[5mERREUR OPENING THE FILE !\x1B[0m" << std::endl;
		return 3;
	}
	return 0;
}

int MyFastScrabble::storeDico()
{
	char str[128];
	std::string fstr;
	while (_myfile.getline(str, 128))
	{
		fstr = str;
		addWordInDico(fstr);
	}
	return 0;
}

int MyFastScrabble::getSizeShrinkDico() const
{
	return _dicoAccordingAnagram.size();
}

void MyFastScrabble::closeFile()
{
	_myfile.close();
}

class CheckOption
{
public:
	CheckOption() : _isOptD(false), _fileName("")
	{};
	~CheckOption() {};

private:
	bool _isOptD;
	std::string _fileName;
public:
	int checkOptions(int ac, char** av)
	{
		if (ac >= 2) {
		for (int i = 1; i < ac; i++) {
			if (av[i][0] == '-' && av[i][1] == 'd' && av[i][2] == '\0'){
					if (ac < 3)
						_isOptD = false;
					else{
						_fileName = av[2];
						_isOptD = true;
					}
				}
			}
		}
		return 0;
	};
	bool getOptionD() const
	{
		return _isOptD;
	};
	std::string getFileName() const
	{
		return _fileName;
	}

};

std::string getAnagramTofind()
{
	std::string aline;

	if (!std::getline(std::cin, aline)){
		throw 42;
	}
	return aline;
}

int work(MyFastScrabble & mfs)
{
	std::string anagram = "";
	anagram = getAnagramTofind();
	mfs.initAnagram(anagram);
	mfs.shrinkDico();
	mfs.findIfWordContainOtherChar();
	mfs.findIfWordContainOnlySameAmountOfLetter();
	return mfs.printResultat();
}

int main(int ac, char **av)
{
	int returnValue = 2;
	int retFile = 0;
	MyFastScrabble mfs;
	CheckOption ch;

	ch.checkOptions(ac, av);
	if (ch.getOptionD())
	{
		retFile = mfs.openFile(ch.getFileName());
		if (retFile != 0)
			return 3;
		mfs.storeDico();
		while (true)
		{
			try{
				returnValue = work(mfs);
			}
			catch (int val)
			{
				mfs.closeFile();
				return returnValue;
			}
			mfs.updateDico();
		}
	}
	return returnValue;
}
