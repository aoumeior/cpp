/*************************************************************************
    > File Name: stat.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月17日 星期六 11时14分18秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argv, char **argc)
{

	if (argv <= 1)
	{
		exit(-1);
	}

	struct stat filestatus;

	if (stat(argc[1], &filestatus) == -1)
	{
		printf("stat init error");
	}

	char *ptr;
	if (S_ISREG(filestatus.st_mode))
		ptr = "regualr";
	else if (S_ISDIR(filestatus.st_mode))
		ptr = "directory";
	else if (S_ISCHR(filestatus.st_mode))
		ptr = "character special";
	else if (S_ISBLK(filestatus.st_mode))
		ptr = "block special";
	else if (S_ISFIFO(filestatus.st_mode))
		ptr = "fifo";

#ifdef S_ISLINK
	else if (S_ISLINK(filestatus.st_mode))
		ptr = "sysbolic link";
#endif

#ifdef S_ISSOCK
	else if (S_ISSOCK(filestatus.st_mode))
		ptr = "socket";
#endif
	else
		ptr = "** unknown mode **";
	printf("%s\n", ptr);

	return 0;
}
