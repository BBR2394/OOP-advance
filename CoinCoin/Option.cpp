#include "Option.hpp"

Option::Option()
{
	
}

Option::Option(int minPrint, int minSave) : _minimumToPrint(minPrint), _minimumToSave(minSave)
{
	
}

Option::~Option()
{
	
}

int Option::getMiniToPrint() const
{
	return _minimumToPrint;
}

void Option::setMinPrint(int mp)
{
	_minimumToPrint = mp;
}

void Option::setMinSave(int ms)
{
	_minimumToSave = ms;
}

int Option::getMinimumToSave() const
{
	return _minimumToSave;
}

