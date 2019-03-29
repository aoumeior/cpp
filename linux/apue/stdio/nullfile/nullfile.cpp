/*************************************************************************
    > File Name: nullfile.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月12日 星期一 19时44分12秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char buf1[] = "abcdef";
char buf2[] = "ABCDEF";

int main()
{

	int fd;

	if ((fd = creat("file.hole", O_WRONLY)) < 0)
	{
		printf("creat error");
		exit(-1);
	}

	if (write(fd, buf1, 10) != 10)
	{
		printf("buf1 write error");
		exit(-1);
	} /* offset now = 10*/

	if (lseek(fd, 40, SEEK_SET) == -1)
	{
		printf("lseek error");
		exit(-1);
	}

	if (write(fd, buf2, 10) != 10)
	{
		printf("buf2 write error");
		exit(-1);
	}

	exit(0);
}
