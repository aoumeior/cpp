/*************************************************************************
    > File Name: umask.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月17日 星期六 19时11分29秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{

	auto old = umask(0);
	printf("%d", old);
	if (creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
		printf("creat error for foo");

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (creat("bar", S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH | S_IROTH | S_IWOTH) < 0)
		printf("creat error for bar");

	return 0;
}
