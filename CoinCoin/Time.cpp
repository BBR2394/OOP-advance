
#include "Time.h"

Time::Time()
{
	time(&_time);
}

Time::~Time()
{
	
}

int Time::getTime()
{
	return _time;
}

int Time::getTimeMS()
{
	return _time;
}