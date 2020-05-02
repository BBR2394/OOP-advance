/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-01 14:56:56
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-02 16:11:36
*/

#include <unistd.h>
#include "MyFastScrabble.h"

MyFastScrabble::MyFastScrabble()
{

}

MyFastScrabble::~MyFastScrabble()
{

}

int MyFastScrabble::initAnagram(std::string anagram)
{
	_anagram = anagram;
	for (int i = 0; i < anagram.size(); i++)
	{
		_anagramSet.insert(anagram[i]);
		_anagramMultiSet.insert(anagram[i]);
		std::cout << "anagram [" << i << "] : " << anagram[i] << std::endl;
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
	return 0;
}

void MyFastScrabble::shrinkDico()
{
	std::string word;
	while (mydico.size() > 0)
	{
		word = mydico.front();
		//std::cout << "word = " << word << std::endl;
		if (word.size() == _anagramSet.size())
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
		//std::cout << "word to compute in third dico = " << word << "  " << wordSave << std::endl;
		while (word.size() > 0) {
			ch = word.back();
			if (_anagramSet.find(ch) == _anagramSet.end())
				break;
			else {
				word.pop_back();
			}
		}
		if (word.size() == 0){
				_dicoaccordingExactLetterAndAnagram.push_back(wordSave);
				// std::cout << "word added in third dico = " << wordSave << std::endl;
			}
		// else{
		// 	std::cout << "word NOT added in third dico = " << wordSave << std::endl;
		// }
		_dicoAccordingAnagram.pop_front();
		//usleep(10000);
	}
	std::cout << "size of the third dico : " << _dicoaccordingExactLetterAndAnagram.size() << std::endl;
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
	//std::multiset<char>::iterator itMSet = _anagramMultiSet.begin();
	char 	ch = '\0';
	while (_dicoaccordingExactLetterAndAnagram.size() > 0)
	{
		word = _dicoaccordingExactLetterAndAnagram.front();
		wordSave = word;
		std::cout << "word to compute in fourth steap " << word << std::endl;
		while (word.size() > 0)
		{
			wordMSet.insert(word.back());
			word.pop_back();
		}
		while (itSet != _anagramSet.end())
		{
			cOne = _anagramMultiSet.count(*itSet);
			cTwo = wordMSet.count(*itSet);
			std::cout << "for letter : " << *itSet << " : cone = " << cOne << " and cTwo = " << cTwo << std::endl;
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
		usleep(10000);
	}
	std::cout << "size of the third dico : " << _dicoWithEqualNumOfChar.size() << std::endl;
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
	//le dico est il trié de base ?
	mydico.sort();
	
	/* si c'est un deque
	while (c < mydico.size())
	{
		std::cout << "word n°" << c << " : " << mydico[c] << std::endl;
		c++;
	}*/
}

int MyFastScrabble::openFile(std::string filename)
{
	_myfile.open(filename);
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
	std::cout << "dico size : " << mydico.size() << std::endl;
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