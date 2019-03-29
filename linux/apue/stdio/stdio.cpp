/*************************************************************************
    > File Name: stdio.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月10日 星期六 15时56分47秒
 ************************************************************************/
// open func
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// close.read.write
// STDOUT_FILENO STDIN_FILENO
// standard output
// standard input
#include <unistd.h>

// exit
#include <stdlib.h>

#define BUFFSIZE 8192

int main(void)
{

	int n;
	char buf[8192];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
		{
			exit(-1);
		}
	}
	if (n < 0)
	{
		exit(-1);
	}
	exit(0);
}
