
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

void Time::update()
{
	this->init();
}

std::string Time::getTimeHumanRead()
{
	return "nothin yet ...";
}

void Time::printTimeHuman()
{
	std::cout << "it is " << ctime(&_time);
}

void Time::printTimeHuman(const time_t  theTime)
{
	std::cout << "it is " << ctime(&theTime);
}

int Time::getTime()
{
	return _time;
}

const time_t Time::getCurentTime()
{
	time(&_time);
	return _time;
}

int Time::getTimeMS()
{
	return _tv.tv_usec;
}