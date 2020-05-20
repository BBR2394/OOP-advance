
#include "CheckOption.h"

CheckOption::CheckOption() : _isOptZ(false), _isOptM(false), _isOptT(false), _trigramOption(""), _minimumVal(0)
{
	
}

CheckOption::~CheckOption()
{
	
}

bool CheckOption::getOptionZ() const
{
	return _isOptZ;
}

bool CheckOption::getOptionT() const
{
	return _isOptT;
}

bool CheckOption::getOptionM() const
{
	return _isOptM;
}

std::string CheckOption::getTriOptionGiven() const
{
	return _trigramOption;
}

int CheckOption::getMinimumOptionGiven() const
{
	return _minimumVal;
}

int CheckOption::setOptTrigram(char *opt)
{
	_trigramOption = opt;
	return 0;
}

int CheckOption::setOptMinimum(char *opt)
{
	try {
		_minimumVal = std::stoi(opt);

	}
	catch(...)
	{
		std::cout << "Nan for the minimum option" << std::endl;
	}
	return 0;
}

/* it is really not the best way to check option, but i will improve it later */
int CheckOption::checkOptions(int ac, char** av)
{
	//std::cout << "dans check option" << std::endl;
	//std::cout << "ac : " << ac << std::endl;
	int i = 1;
	/*
	** j'avais fait un code extremement simpliste et basique pour l'option -z
	** c'est a refaire pour les autres options
	*/
	int c = 0;
	if (ac >= 2) {
		while (i < ac) {
			if (av[i][0] == '-' && av[i][1] == 'z' && av[i][2] == '\0')
				_isOptZ = true;
			if (av[i][0] == '-' && av[i][1] == 't' && av[i][2] == '\0')
				{
					if (i+1 >= ac)
						throw std::string("input for parameter is invalid");
					setOptTrigram(av[i+1]);
					_isOptT = true;
					i++;
				}
			if (av[i][0] == '-' && av[i][1] == 'm' && av[i][2] == '\0')
				{
					if (i+1 >= ac)
						throw std::string("input for parameter is invalid");
					setOptMinimum(av[i+1]);
					_isOptM = true;
					i++;
				}
			i++;
			//c ne sert a rien seulement quand j'aurais refait tout ca 
			c++;
		}
	}
	return 0;
}