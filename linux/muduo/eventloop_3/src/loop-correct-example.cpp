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

int main()
{
	std::cout << "main(): pid = " << getpid() << "tid = " << CurrentThread::tid() << std::endl;

	EventLoop loop_1;
	loop_1.loop();

	EventLoop loop_2;
	loop_2.loop();
	return 0;
}
