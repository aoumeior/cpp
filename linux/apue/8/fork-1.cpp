/*************************************************************************
    > File Name: fork-1.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月20日 星期二 08时28分54秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{

	pid_t pid;

	if ((pid = fork()) < 0)
	{
		printf("fork error");
		exit(-1);
	}
	else if (pid == 0)
	{

		if ((pid = fork()) < 0)
		{
			printf("fork error");
			exit(-1);
		}
		else if (pid > 0)
		{
			exit(0);
		}

		sleep(2);
		printf("second child ,parent pid = %d\n", getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid)
	{
		printf("watipid error");
		exit(-1);
	}

	exit(0);
}
