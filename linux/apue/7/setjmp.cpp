/*************************************************************************
    > File Name: setjmp.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月19日 星期一 12时08分50秒
 ************************************************************************/

#include <setjmp.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

#define TOK_ADD 5
#define MAXLINE 200

int get_token();
void cmd_add(void);
void do_line(char *);
jmp_buf jmpbuffer;

int main(void)
{

	char line[MAXLINE];

	if (setjmp(jmpbuffer) != 0)
	{
		printf("error\n");
	}

	while (fgets(line, MAXLINE, stdin) != NULL)
		do_line(line);
	exit(0);
}

char *tok_ptr;

void do_line(char *ptr)
{

	int cmd;
	tok_ptr = ptr;
	while ((cmd = get_token()) > 0)
	{
		switch (cmd)
		{
		case TOK_ADD:
			cmd_add();
			break;
		}
	}
}
int get_token()
{
	static int i = -1;
	if (i == -1)
		i = 5;
	else
		i = -1;

	return i;
}
void cmd_add(void)
{

	int token;
	token = get_token(); /* an error has occurred */
	if (token < 0)
	{
		longjmp(jmpbuffer, 1);
		/* rest of processing for this command */
	}
}
