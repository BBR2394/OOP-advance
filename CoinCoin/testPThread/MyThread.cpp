/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-30 11:30:34
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-30 12:11:12
*/

#include "MyThread.h"

MyThread::MyThread()
{

}

MyThread::~MyThread()
{

}

//pthread_create(&tinfo[tnum].thread_id, &attr, &thread_start, &tinfo[tnum]);

void	*start_thread(void *data)
{
	t_dt_thread *mydata = (t_dt_thread*)data;
	std::cout << "dans le thread " << mydata->nb << std::endl;
	return NULL;
}

int MyThread::startThread()
{
	std::cout << "i am going to start the thread" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		t_dt_thread *data = new t_dt_thread;
		data->nb = 42 + i;
		pthread_create(&(_thread), NULL, start_thread, data);
	}
	sleep(20);
	return 0;
}