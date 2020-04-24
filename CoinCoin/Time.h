
#ifndef TIME_H_
# define TIME_H_

#include <iostream>

#include <ctime>

class Time
{
public:
	Time();
	~Time();

private:
	time_t	_time;

public:
	int getTime();
	int getTimeMS();
};

#endif