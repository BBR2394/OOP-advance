
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
	bool _isOptSave;
	std::string _trigramOption;
	int _minimumVal;
	int setOptTrigram(char *);
	bool setOptMinimum(char *);
	bool setOptSave(char *);

public:
	int checkOptions(int, char**);
	bool getOptionZ() const;
	bool getOptionT() const;
	bool getOptionM() const;
	bool getOptionSave() const;
	std::string getTriOptionGiven() const;
	int getMinimumOptionGiven() const;
};

#endif