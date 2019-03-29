/*************************************************************************
    > File Name: orphanedprocessgroupst.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月30日 星期五 22时19分31秒
 ************************************************************************/

#include <sys/types.h>
#include <error.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void sig_hup(int);
static void pr_ids(char *);

int main(void)
{

	char c;
	pid_t pid;

	pr_ids("parens");

	if ((pid = fork()) < 0)
		printf("fork error");
	else if (pid > 0)
	{
		sleep(5);
		exit(0);
	}
	else
	{
		pr_ids("child");
		signal(SIGHUP, sig_hup);
		kill(getpid(), SIG)
	}
}
