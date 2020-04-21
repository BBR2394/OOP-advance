
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