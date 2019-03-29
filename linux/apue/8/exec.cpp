/*************************************************************************
    > File Name: exec.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月20日 星期二 10时10分32秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *env_init[] = {
	"USER=unknown",
	"PATH=/tmp",
	NULL};

int main()
{

	pid_t pid;

	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(-1);
	}
	else if (pid == 0)
	{

		if (execle("/home/aoumeior/", "echoall", "myarg1", "MY ARG2",
				   (char *)0, env_init))
		{
			printf("execle error");
			exit(-1);
		}
	}
	if (waitpid(pid, NULL, 0) < 0)
	{
		printf("waitpid error\n");
		exit(-1);
	}

	if ((pid = fork()) < 0)
	{
		printf("fork error");
		exit(-1);
	}
	else if (pid == 0)
	{
		if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
		{
			printf("execlp error ");
		}
	}
	exit(-1);
}
