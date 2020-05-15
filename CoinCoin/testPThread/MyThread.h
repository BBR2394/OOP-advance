
#ifndef MYTHREAD_H_
# define MYTHREAD_H_

#include <iostream>

#include <unistd.h>
#include <pthread.h>

typedef struct s_dataFotHtread {

	int nb;

} t_dt_thread;

class MyThread
{
public: 
	MyThread();
	~MyThread();

private:
	pthread_t			_thread;

public:
	int startThread();

};

#endif