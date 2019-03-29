/*************************************************************************
    > File Name: fork.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月10日 星期六 17时34分05秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/wait.h>

// fork and other function
#include <unistd.h>

// strlen function
#include <string.h>

// exit function
#include <stdlib.h>

#include <stdio.h>

const int MAXLINE = 8192;
int main(void)
{

	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");

	// 如果fgets 获取的第一个字符是 文件结束符 ，则 返回 NULL
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		buf[strlen(buf) - 1] = 0;

		if ((pid = fork()) < 0)
		{
			exit(-1); // fail
		}
		else if (pid == 0)
		{ // child
			// execlp 执行从标准输入的命令
			execlp(buf, buf, (char *)0);
			printf("can't execute");
			exit(127);
		}

		// parent
		if ((pid = waitpid(pid, &status, 0)) < 0)
			exit(-1);
		printf("%% ");
	}
	exit(0);
}
