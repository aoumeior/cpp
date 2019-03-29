/*************************************************************************
    > File Name: channel.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年02月07日 星期三 12时34分06秒
 ************************************************************************/

#include "channel.h"
#include "eventloop.h"
#include <poll.h>
const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = POLLIN | POLLPRI;
const int Channel::kWriteEvent = POLLOUT;

Channel::Channel(EventLoop *loop, int fdArg)
		: loop_(loop),
			fd_(fdArg),
			events_(0),
			revents_(0),
			index_(-1)
{
}

void Channel::update()
{
	loop_->updateChannel(this);
}
