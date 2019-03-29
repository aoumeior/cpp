/*************************************************************************
    > File Name: competecondition.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月20日 星期二 09时22分20秒
 ************************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

static void charatatime(char *);

int main(void)
{

	pid_t pid;

	if ((pid = fork()) < 0)
	{
		printf("fork error");
	}
	else if (pid == 0)
	{
		charatatime("output from child\n");
	}
	else
	{
		charatatime("output from parent\n");
	}

	return 0;
}

static void charatatime(char *str)
{

	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for (ptr = str; c != '\0'; c = *(++ptr))
	{
		putc(c, stdout);
	}
}
