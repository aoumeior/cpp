/*************************************************************************
    > File Name: fork.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月19日 星期一 16时18分15秒
 ************************************************************************/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int glob = 6;
char buf[] = "a write to stdout\n";

int main(void)
{

	int var; /* automatic variable on the stack*/
	pid_t pid;

	var = 88;

	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
	{
		printf("write error");
		exit(-1);
	}

	printf("beforre fork \n");

	if ((pid = fork()) < 0)
	{
		printf("fork error");
		exit(-1);
	}
	else if (pid == 0)
	{
		glob++;
		var++;
	}
	else
	{
		sleep(2);
	}

	printf("pid = %d, glob =%d, var =%d\n", getpid(), glob, var);

	return 0;
}
