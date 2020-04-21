
#include "CheckOption.h"

CheckOption::CheckOption()
{
	
}

CheckOption::~CheckOption()
{
	
}

int CheckOption::checkOptions(int ac, char** av)
{
	std::cout << "dans check option" << std::endl;
	std::cout << "ac : " << ac << std::endl;
	if (ac > 2) {
		std::cout << "ac : " << ac << " av : " << av[0] << '\n' << av[1] << std::endl;
	}
	return 0;
}