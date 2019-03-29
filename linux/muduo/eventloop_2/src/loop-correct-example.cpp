/*************************************************************************
    > File Name: loop-test.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年02月06日 星期二 20时22分33秒
 ************************************************************************/

#include <iostream>
#include "eventloop.h"
#include <pthread.h>
#include <unistd.h>

EventLoop *g_loop;

void *threadFunc(void *)
{
	g_loop->loop();
}

int main()
{
	std::cout << "main(): pid = " << getpid() << "tid = " << CurrentThread::tid() << std::endl;

	EventLoop loop;
	g_loop = &loop;
	pthread_t thr;
	if (pthread_create(&thr, NULL, &threadFunc, NULL))
	{
		std::cout << "create fail" << std::endl;
		return -1;
	}

	loop.loop();
	pthread_exit(NULL);
	return 0;
}
