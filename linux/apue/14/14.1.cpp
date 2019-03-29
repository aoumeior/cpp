/*************************************************************************
    > File Name: 14.0.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月31日 星期六 22时51分27秒
 ************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAXLINE 4096
int main(void)
{

	int n, fd[2];

	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd) < 0)
	{
		printf("pip error");
		exit(-1);
	}

	if ((pid = fork()) < 0)
	{
		printf("fork error");
		exit(-1);
	}
	else if (pid > 0)
	{
		close(fd[0]);
		write(fd[1], "hello word\n", 12);
	}
	else
	{
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
	exit(-1);
}
