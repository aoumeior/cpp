/*************************************************************************
    > File Name: fcntl.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月13日 星期二 11时48分23秒
 ************************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void set_fl(int fd, int flags)
{
	int val;

	if ((val = fcntl(fd, F_GETFL, 0)))
	{
		printf("fcntl F_GETFL error");
		exit(-1);
	}

	val |= flags; /* turn on flags */
	/* val &| = ~flags  turn off flags */

	if (fcntl(fd, F_SETFL, val) < 0)
	{
		printf("fcntl F_SETFL error");
	}
}

int main()
{
}
