/*************************************************************************
    > File Name: sigprocmask.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月19日 星期一 19时18分25秒
 ************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void sig_quit(int);

int main(void)
{

	sigset_t newmask, oldmask, pendmask;

	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
	{
		printf("can't catch SIGQUIT");
		exit(-1);
	}

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);

	// sigprocmask 新的信号屏蔽集 为当前信号屏蔽字和 set指向信号集的并集 ， newmask包含我们希望阻塞的附加信号
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
	{
		printf("SIG_BLOCK error");
		exit(-1);
	}
	sleep(5);
	// 返回对于调用进程被阻塞不能递迭和当前为决的信号集
	if (sigpending(&pendmask) < 0)
	{
		printf("sigpending error");
		exit(-1);
	}

	if (sigismember(&pendmask, SIGQUIT))
	{
		printf("\nSIGQUIT sigpending\n");
	}

	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
	{
		printf("SIG_SETMASK error");
		exit(-1);
	}

	printf("SIGQUIT unblocked\n");
	sleep(5);

	return 0;
}

static void sig_quit(int signo)
{

	printf("caught SIGQUIT\n");

	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
	{
		printf("can't reset SIGQUIT");
		exit(-1);
	}

	return;
}
