/*************************************************************************
    > File Name: daemon_init.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月08日 星期四 22时36分25秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int daemon_init(void)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		return -1;
	else if (pid != 0)
		exit(0);

	/* become session leader */
	setsid();
	/* change working directory */
	chdir("/");
	/* clear our file mode creation mask */
	umask(0);
	return 0;
}
int main()
{

	daemon_init();

	close(0);
	close(1);
	close(2);
#define MAXLINE 100

	char *ptr, buff[MAXLINE];

	ptr = getlogin();

	sprintf(buff, "login name: %s\n", (ptr == NULL) ? "empty" : ptr);
	write(3, buff, strlen(buff));

	return 0;
}
