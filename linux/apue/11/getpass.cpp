/*************************************************************************
    > File Name: getpass.h
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月21日 星期三 16时46分23秒
 ************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

#define MAX_PASS_LEN 8

char *getpass(const char *prompt)
{

	static char buf[MAX_PASS_LEN];
	char *ptr;
	sigset_t sig, sigsave;
	struct termios term, termsave;
	FILE *fp;
	int c;

	if ((fp = fopen(ctermid(NULL), "r+")) == NULL)
	{
		return NULL;
	}

	setbuf(fp, NULL);

	sigemptyset(&sig);
	sigaddset(&sig, SIGINT);
	sigaddset(&sig, SIGTSTP);

	sigprocmask(SIG_BLOCK, &sig, &sigsave);

	tcgetattr(fileno(fp), &termsave);
	term = termsave;
	term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
	tcsetattr(fileno(fp), TCSAFLUSH, &term);

	fputs(prompt, fp);
	ptr = buf;

	while ((c = getc(fp)) != EOF && c != '\n')
	{

		if (ptr < &buf[MAX_PASS_LEN])
			*ptr++ = c;
	}
	*ptr = 0;
	putc('\n', fp);
	tcsetattr(fileno(fp), TCSAFLUSH, &termsave);
	sigprocmask(SIG_SETMASK, &sigsave, NULL);

	fclose(fp);
	return ptr;
}

int main(void)
{

	char *ptr;
	if ((ptr = getpass("ENTER password:")) == NULL)
	{
		printf("getpass error");
		exit(-1);
	}
	printf("Password: %s\n", ptr);

	while (*ptr != 0)
	{

		*ptr++ = 0;
	}
	return 0;
}
