/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-01 14:56:46
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-02 16:16:12
*/

#include <iostream>

#include "MyFastScrabble.h"

int main(int ac, char **av)
{
	MyFastScrabble mfs;
	
	mfs.openFile("./monDico.txt");
	//mfs.openFile("./words.txt");
	
	std::cout << "here is where the magik happen" << std::endl;
	mfs.storeDico();

	mfs.initAnagram("itnavnel");
	//mfs.initAnagram("irelacv");
	//mfs.initAnagram("rdow");

	mfs.printAnagram();
	//mfs.printDico();
	mfs.shrinkDico();
	//mfs.printShrinkDico();`
	std::cout << "shrink dico size : " << mfs.getSizeShrinkDico() << std::endl;
	mfs.findIfWordContainOtherChar();
	mfs.printThirdDico();
	mfs.findIfWordContainOnlySameAmountOfLetter();
	mfs.closeFile();
	return 0;
}