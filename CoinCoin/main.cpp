/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-20 17:08:14
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-26 22:00:12
*/

#include <iostream>

#include "MyMiner.h"
#include "CheckOption.h"

int main(int ac, char **av)
{
	MyMiner mm;
	CheckOption chckOpt;

	std::cout << "here is where the magik happen !" << std::endl;
	chckOpt.checkOptions(ac, av);

	mm.mine(chckOpt);
}