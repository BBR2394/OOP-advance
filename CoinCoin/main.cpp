/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-20 17:08:14
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-22 15:21:24
*/

#include <iostream>

#include "MyMiner.h"
#include "CheckOption.h"

int main(int ac, char **av)
{
	MyMiner mm;
	CheckOption chckOpt;

	std::cout << "here is where the magik happen !" << std::endl;
	try {
		chckOpt.checkOptions(ac, av);
	}
	catch(std::string r)
	{
		std::cout << r << std::endl;
		return -1;
	}
	mm.mine(chckOpt);
}