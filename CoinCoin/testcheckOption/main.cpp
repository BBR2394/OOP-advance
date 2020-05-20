/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-26 21:26:40
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-17 21:31:51
*/

#include "../CheckOption.h"

int main(int ac, char **av)
{
	CheckOption _co;

	try
	{
		_co.checkOptions(ac, av);
	}
	catch(std::string c)
	{
		std::cout << "Cathed : " << c << std::endl;
	}
	std::cout << "is opt z : " << _co.getOptionZ() << std::endl;
	std::cout << "is opt t : " << _co.getOptionT() << std::endl;
	if (_co.getOptionT())
		std::cout << "l'option T " << _co.getTriOptionGiven() << std::endl;
	std::cout << "is opt m : " << _co.getOptionM() << std::endl;
	if (_co.getOptionM())
		std::cout << "l'option M " << _co.getMinimumOptionGiven() << std::endl;

	return 0;
}