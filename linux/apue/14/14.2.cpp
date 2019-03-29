/*************************************************************************
    > File Name: 14.2.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月31日 星期六 23时26分05秒
 ************************************************************************/

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEF_PAGER "/bin/more"
#define MAXLINE 4096
int main(int argc, char *argv[])
{

	int n, fd[2];
	pid_t pid;
	char line[MAXLINE], *pager, *argv0;

	FILE *fp;

	if (argc != 2)
	{
		printf("usage: a.out <pathname>");
		exit(-1);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("can't open %s", argv[1]);
	}

	if (pipe(fd) < 0)
	{
		printf("pipe error");
		exit(-1);
	}

	if ((pid = fork()) < 0)
	{
		printf("fork error");
		exit(-1);
	}
	else if (pid > 0)
	{
		close(fd[0]);
		while (fgets(line, MAXLINE, fp) != NULL)
		{
			n = strlen(line);
			if (write(fd[1], line, n) != n)
			{
				printf("write error to pipe");
				exit(-1);
			}
		}
		if (ferror(fp))
		{
			printf("fgets error");
			exit(-1);
		}
		close(fd[1]);
		if (waitpid(pid, NULL, 0) < 0)
		{
			printf("waitpid error");
			exit(-1);
		}
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (fd[0] != STDIN_FILENO)
		{
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
			{
				printf("dup2 error to stdin");
				exit(-1);
			}
			close(fd[0]);
		}
		if ((pager = getenv("PAGER")) == NULL)
		{
			pager = DEF_PAGER;
		}
		if ((argv0 = strrchr(pager, '/')) != NULL)
		{
			argv0++;
		}
		else
		{
			argv0 = pager;
		}

		if (execl(pager, argv0, (char *)0) < 0)
		{
			printf("execl error for %s", pager);
			exit(-1);
		}
	}

	return 0;
}
