/*************************************************************************
    > File Name: stdio0.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月10日 星期六 17时10分11秒
 ************************************************************************/

#include <stdio.h>

#include <stdlib.h>

int main(void)
{

	int c;
	while ((c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
		{
			exit(-1);
		}
	}

	if (ferror(stdin))
		exit(-1);
	exit(0);
}
