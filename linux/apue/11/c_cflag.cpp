/*************************************************************************
    > File Name: c_cflag.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月20日 星期二 09时26分14秒
 ************************************************************************/

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	struct termios term;
	int size;

	if (tcgetattr(STDIN_FILENO, &term) < 0)
	{
		printf("tcgetattr error");
		exit(-1);
	}

	size = term.c_cflag & CSIZE;
	if (size == CS5)
		printf("5 bits/byte\n");
	else if (size == CS6)
		printf("6 bits/byte\n");
	else if (size == CS7)
		printf("6 bits/byte\n");
	else if (size == CS8)
		printf("6 bits/byte\n");
	else
		printf("unkonw bits/byte\n");

	term.c_cflag &= ~CSIZE;
	term.c_cflag |= CS8;

	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) < 0)
	{

		printf("tcsetattr error");
		exit(-1);
	}

	return 0;
}
