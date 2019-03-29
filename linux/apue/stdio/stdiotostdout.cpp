/*************************************************************************
    > File Name: stdiotostdout.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月13日 星期二 00时15分22秒
 ************************************************************************/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFSIZE 8192
int main()
{

	int n;
	char buf[BUFFSIZE];
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		printf("%d\n", n);
		if (write(STDOUT_FILENO, buf, n) != n)
		{
			printf("write error");
			exit(-1);
		}
	}
	if (n < 0)
	{
		printf("read error");
		exit(-1);
	}

	exit(0);
}
