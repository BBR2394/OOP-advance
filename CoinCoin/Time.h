
#ifndef TIME_H_
# define TIME_H_

#include <iostream>
#include <chrono>

#include <ctime>
#include <sys/time.h>

class Time
{
public:
	Time();
	~Time();

private:
	time_t	_time;
	struct timeval _tv;

public:
	void init();
	void update();
	std::string getTimeHumanRead();
	void printTimeHuman();
	void printTimeHuman(const time_t);
	void printTime();
	int getTime();
	int getTimeMS();
	const time_t getCurentTime();
};

#endif