
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
	bool _isOptM;
	bool _isOptT;
public:
	int checkOptions(int, char**);
	bool getOptionZ() const;

};

#endif