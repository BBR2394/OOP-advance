#include "Option.hpp"

Option::Option() :  _save(false)
{
	
}

Option::Option(int minPrint, int minSave) : _minimumToPrint(minPrint), _minimumToSave(minSave), _save(false)
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

bool Option::getIfSave() const
{
	return _save;
}

void Option::setMinSave(int ms)
{
	_minimumToSave = ms;
}

void Option::setIfSave()
{
	_save = true;
}

int Option::getMinimumToSave() const
{
	return _minimumToSave;
}

