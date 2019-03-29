/*************************************************************************
    > File Name: channel.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年02月07日 星期三 12时06分52秒
 ************************************************************************/

#include <iostream>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
class EventLoop;

class Channel : boost::noncopyable
{
  public:
	typedef boost::function<void()> EventCallback;
	Channel(EventLoop *loop, int fd);
	void HandleEvent();
	void setReadCallback(const EventCallback &cb)
	{
		this->readCallback = cb;
	}
	void setWriteCallback(const EventCallback &cb)
	{
		this->writeCallback = cb;
	}
	void setErrorCallback(const EventCallback &cb)
	{
		this->errorCallback = cb;
	}

	int fd() const
	{
		return fd_;
	}

	int events() const
	{
		return events_;
	}
	void set_revents(int revt)
	{
		events_ = revt;
	}
	bool isNoneEvents() const
	{
		return events_ == kNoneEvent;
	}

	void enableReading()
	{
		events_ |= kReadEvent;
		update();
	}
	void enableWriting()
	{
		events_ |= kWriteEvemt;
		update();
	}

	// for Poller
	int index()
	{
		return index_;
	}
	void set_index(int idx)
	{
		index_ = idx;
	}

	EventLoop *ownerLoop()
	{
		return loop_;
	}

  private:
	void update();
	static const int kNoneEvent;
	static const int kReadEvent;
	static const int kWriteEvemt;

	EventLoop *loop_;
	const int fd_;
	int events_;
	int revents_;
	int index_;

	EventCallback readCallback;
	EventCallback writeCallback;
	EventCallback errorCallback;
};
