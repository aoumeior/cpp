/*************************************************************************
    > File Name: signal.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月17日 星期六 17时02分50秒
 ************************************************************************/

#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void my_alarm(int);

int main(void)
{

	struct passwd *ptr;

	signal(SIGALRM, my_alarm);
	alarm(0);
	for (;;)
	{
		if ((ptr = getpwnam("aoumeior")) == NULL)
		{
			printf("getpwnam error");
			exit(-1);
		}
		if (strcmp(ptr->pw_name, "aoumeior") != 0)
			printf("return value corrupted!, pw_name is  %s\n", ptr->pw_name);
	}
}

static void my_alarm(int signo)
{

	struct passwd *rootptr;
	printf("in signal handler\n");

	if ((rootptr = getpwnam("root")) == NULL)
	{
		printf("getpwnam(root) error");
	}
	alarm(1);
	return;
}
