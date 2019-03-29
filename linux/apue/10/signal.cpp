/*************************************************************************
    > File Name: signal.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月08日 星期四 23时15分54秒
 ************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static void sig_usr(int);

int main(void)
{

	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
	{
		exit(-1);
	}

	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
		exit(-1);
	}

	for (;;)
		pause();
	return 0;
}

static void sig_usr(int signo)
{

	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signal %d\n", signo);
	return;
}
