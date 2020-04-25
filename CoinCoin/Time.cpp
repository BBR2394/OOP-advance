
#include "Time.h"

Time::Time()
{
	init();
}

Time::~Time()
{
	
}

void Time::init()
{
	time(&_time);
	gettimeofday(&_tv, NULL);
}

void Time::printTime()
{
	std::cout << "in time print" << std::endl;
}

int Time::getTime()
{
	return _time;
}

int Time::getTimeMS()
{
	return _tv.tv_usec;
}