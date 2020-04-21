
#ifndef CHECKOPTION_H_
# define CHECKOPTION_H_

#include <iostream>

class CheckOption
{
public:
	CheckOption();
	~CheckOption();

private:
	bool _isOptZ;

public:
	int checkOptions(int, char**);


};

#endif