/*************************************************************************
    > File Name: system.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月20日 星期二 11时18分33秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int system(const char *cmdstring)
{

	pid_t pid;
	int status;

	if (cmdstring == NULL)
		return 1;

	if ((pid = fork()) < 0)
	{
		status = -1;
	}
	else if (pid == 0)
	{
		execl("/bin/sh", "sh", "-C", cmdstring, (char *)0);
		_exit(127);
	}
	else
	{
		while (waitpid(pid, &status, 0) < 0)
		{
			if (errno != EINTR)
			{
				status = -1;
				break;
			}
		}
	}

	return status;
}

int main(void)
{
	int status;

	if ((status = system("date")) < 0)
	{

		printf("system() error");
	}
	return 0;
}
