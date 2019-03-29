/*************************************************************************
    > File Name: 3test6.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月14日 星期三 20时38分19秒
 ************************************************************************/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	if ((fd = open("./test.txt", O_RDWR | O_APPEND, 0)) == -1)
	{
		printf(" open fail\n");
		return -1;
	}

	int model;
	model = fcntl(fd, F_GETFL, 0);
	printf("%d\n", model);

	model &= O_APPEND;
	printf("%d\n", model);

	off_t off;
	off = lseek(fd, 20, SEEK_SET);
	printf("%ld\n", off);

	char buf[] = "abcdefghijk";
	write(fd, buf, sizeof buf);

	off = lseek(fd, -10, SEEK_CUR);
	printf("%ld\n", off);

	write(fd, buf, sizeof buf);

	return 0;
}
