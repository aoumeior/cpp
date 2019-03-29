/*************************************************************************
    > File Name: signalSample.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月17日 星期六 18时27分55秒
 ************************************************************************/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void sig_alrm(int signal)
{
	return;
}

unsigned int sleep1(unsigned int nesecs)
{

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return (nesecs);
	alarm(nesecs);
	pause();
	return (alarm(0));
}
