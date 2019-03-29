/*************************************************************************
    > File Name: setjmpsolvesleep.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月17日 星期六 20时12分35秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
#include <stdlib.h>

static jmp_buf env_alrm;

static void sig_alrm(int sign)
{

	longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int nsecs)
{

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return nsecs;
	if (setjmp(env_alrm) == 0)
	{
		alarm(nsecs);
		pause();
	}
	return alarm(0);
}

static void sig_int(int signo)
{
	int i;
	volatile int j;

	printf("\nsig_int starting\n");
	for (i = 0; i < 2000000000; i++)
	{
		j += i * i;
	}

	printf("sig_int finished\n");
	return;
}

int main(void)
{

	unsigned int unslept;

	if (signal(SIGINT, sig_int))
	{
		printf("signal(SIGINT)");
		exit(-1);
	}
	unslept = sleep2(5);
	printf("sleep2 returned: %u\n", unslept);
	exit(0);
}
