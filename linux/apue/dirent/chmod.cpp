/*************************************************************************
    > File Name: chmod.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月17日 星期六 19时31分58秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

	struct stat statbuf;

	/* turn on set-group-Id and turn off group-execute */

	if (stat("foo", &statbuf) < 0)
		printf("stat error for foo");
	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		printf("chmod error for foo");

	/* set absolute mode to "rw-r--r--" */
}
