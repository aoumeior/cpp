/*************************************************************************
    > File Name: unlink.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月17日 星期六 19时52分32秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{

	if (open("tempfile", O_RDWR) < 0)
		printf("open error");

	if (unlink("tempfile") < 0)
		printf("unlink error");

	sleep(15);
	printf("file unlinked\n");
}
