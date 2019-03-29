/*************************************************************************
    > File Name: lseek.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月12日 星期一 19时20分35秒
 ************************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
	{
		printf("cannot seek\n");
	}
	else
	{
		printf("seek Ok\n");
	}
	exit(0);
}
