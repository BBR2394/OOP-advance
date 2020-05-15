/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-26 21:26:40
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-26 21:35:00
*/

#include "../CheckOption.h"

int main(int ac, char **av)
{
	CheckOption _co;

	_co.checkOptions(ac, av);
	std::cout << "is opt z : " << _co.getOptionZ() << std::endl;
	return 0;
}