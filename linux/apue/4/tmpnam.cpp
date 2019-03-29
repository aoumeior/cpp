/*************************************************************************
    > File Name: tmpnam.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月18日 星期日 12时34分35秒
 ************************************************************************/

#include <stdio.h>

#define MAXLINE 1024

int main(void)
{

	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;
	printf("%s\n", tmpnam(NULL));

	tmpnam(name);
	printf("%s\n", name);

	if ((fp = tmpfile()) == NULL)
	{

		printf("tempfile error");
		return -1;
	}

	fputs("one line of output \n", fp);

	/* then read it back */
	/* 将文件指针重新定位在文件开始*/
	rewind(fp);

	if (fgets(line, sizeof line, fp) == NULL)
	{
		printf("fgets error");
		return -1;
	}

	fputs(line, stdout);
	return 0;
}
