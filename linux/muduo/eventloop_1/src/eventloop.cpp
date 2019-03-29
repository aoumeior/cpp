/*************************************************************************
    > File Name: event_loop.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年02月06日 星期二 19时54分16秒
 ************************************************************************/

#include "eventloop.h"
#include <assert.h>
#include <poll.h>

__thread EventLoop *t_loopInThisThread = 0;

EventLoop::EventLoop()
	: looping_(false),
	  threadId_(CurrentThread::tid())
{
	if (t_loopInThisThread)
	{
		// assert fail
		assert(false);
	}
	else
	{
		t_loopInThisThread = this;
	}
}

EventLoop::~EventLoop()
{
	assert(!looping_);
	t_loopInThisThread = 0;
}

void EventLoop::loop()
{
	assert(!looping_);
	assertInLoopThreaad();
	looping_ = true;
	::poll(NULL, 0, 5 * 1000);
	std::cout << "EventLoop " << this << " stop" << std::endl;
	looping_ = false;
}
