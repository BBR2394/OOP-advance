/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-01 14:56:46
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-07 12:29:09
*/

#include <iostream>
#include <ctime>

#include "MyFastScrabble.h"

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

	//std::cin >> aline;
	if (!std::getline(std::cin, aline)){
		std::cout << "EOF !" << std::endl;
		throw 42;
	}
	//std::cout << " l'anagram : " << aline << std::endl;
	return aline;
}

int work(MyFastScrabble & mfs)
{
	std::time_t result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result)) << result << " seconds since the Epoch\n";
	std::cout << "ici ca commence" << std::endl;
	std::string anagram = "";
	anagram = getAnagramTofind();
	result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result)) << result << " seconds since the Epoch\n";
	mfs.initAnagram(anagram);
	//mfs.initAnagram("itnavnel");
	//mfs.initAnagram("irelacv");
	//mfs.initAnagram("rdow");

	//mfs.printAnagram();
	//mfs.printDico();
	
	mfs.shrinkDico();
	
	//mfs.printShrinkDico();
	
	//std::cout << "shrink dico size : " << mfs.getSizeShrinkDico() << std::endl;

	mfs.findIfWordContainOtherChar();
	//mfs.printThirdDico();

	mfs.findIfWordContainOnlySameAmountOfLetter();
	std::cout << "Resultat : " << std::endl;
	result = std::time(nullptr);
	std::cout << std::asctime(std::localtime(&result)) << result << " seconds since the Epoch\n";
	return mfs.printResultat();

	//mfs.printFourthDico();
	return 0;
}

int main(int ac, char **av)
{
	int returnValue = 2;
	int retFile = 0;
	MyFastScrabble mfs;
	CheckOption ch;

	ch.checkOptions(ac, av);
	//std::cout << "res opt D " << ch.getOptionD() << " " << ch.getFileName() << std::endl;
	if (ch.getOptionD())
	{
		//returnValue = mfs.openFile("./monDico.txt");
		//returnValue = mfs.openFile("./words.txt");
		//returnValue = mfs.openFile("./couldnotopenfile.txt");
		retFile = mfs.openFile(ch.getFileName());
		if (retFile != 0)
			return 3;
		std::cout << "here is where the magik happen" << std::endl;
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