/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-25 16:43:51
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-25 19:43:00
*/

#include <iostream>

#include "../Time.h"

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>


int main()
{
	struct timeval tv;
	Time tm;
	gettimeofday(&tv, NULL);

	unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;

    /*for (int i = 0; i < 100; i++)
    {
    	gettimeofday(&tv, NULL);
    	millisecondsSinceEpoch = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
		printf("milisecond %llu\n", millisecondsSinceEpoch);
		printf("%d\n", tv.tv_usec);
		//usleep();
	}*/
	std::cout << "dans mon object time " << tm.getTimeMS() << std::endl;
	tm.init();
	std::cout << "dans mon object time " << tm.getTimeMS() << std::endl;
	tm.printTimeHuman();
	tm.printTimeHuman(tm.getCurentTime());
	std::cout << "l epoch " << (int)tm.getCurentTime() << std::endl;
	sleep(1);
	tm.printTimeHuman(tm.getCurentTime());
	return 0;
}