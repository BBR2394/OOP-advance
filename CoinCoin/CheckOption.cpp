
#include "CheckOption.h"

CheckOption::CheckOption() : _isOptZ(false), _isOptM(false), _isOptT(false)
{
	
}

CheckOption::~CheckOption()
{
	
}

bool CheckOption::getOptionZ() const
{
	return _isOptZ;
}

/* it is really not the best way to check option, but i will improve it later */
int CheckOption::checkOptions(int ac, char** av)
{
	//std::cout << "dans check option" << std::endl;
	//std::cout << "ac : " << ac << std::endl;
	if (ac >= 2) {
		for (int i = 1; i < ac; i++) {
			if (av[i][0] == '-' && av[i][1] == 'z')
				_isOptZ = true;
		}
	}
	return 0;
}