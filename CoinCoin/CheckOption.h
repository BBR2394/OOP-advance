
#ifndef CHECKOPTION_H_
# define CHECKOPTION_H_

#include <iostream>
#include <cstdlib>

class CheckOption
{
public:
	CheckOption();
	~CheckOption();

private:
	bool _isOptZ;
	bool _isOptM;
	bool _isOptT;
	std::string _trigramOption;
	int _minimumVal;
	int setOptTrigram(char *);
	int setOptMinimum(char *);

public:
	int checkOptions(int, char**);
	bool getOptionZ() const;
	bool getOptionT() const;
	bool getOptionM() const;
	std::string getTriOptionGiven() const;
	int getMinimumOptionGiven() const;
};

#endif