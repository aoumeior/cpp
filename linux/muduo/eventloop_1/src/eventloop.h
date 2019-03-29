/*************************************************************************
    > File Name: event_loop.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年02月06日 星期二 19时30分17秒
 ************************************************************************/
#include <iostream>
#include <boost/noncopyable.hpp>
#include <syscall.h>
#include <unistd.h>
#include <time.h>
using namespace std;

class CurrentThread : boost::noncopyable
{
  public:
	static pid_t tid()
	{
		return syscall(SYS_gettid);
	}
};

class EventLoop : boost::noncopyable
{
  public:
	EventLoop();
	~EventLoop();

	void loop();
	void assertInLoopThreaad()
	{
		if (!isInloopThread())
		{
			abortNotInLoopThread();
		}
	}
	bool isInloopThread() const
	{
		return threadId_ == CurrentThread::tid();
	}

  private:
	void abortNotInLoopThread()
	{
		std::cout << "this is abortNotInLoopThread" << std::endl;
	}

	bool looping_;
	const pid_t threadId_;
};
