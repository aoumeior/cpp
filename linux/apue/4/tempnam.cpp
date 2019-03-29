/*************************************************************************
    > File Name: tempnam.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月18日 星期日 13时36分02秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char **argv)
{

	if (argc != 3)
	{
		printf("usage: a.out <directory> <prefix>");
		return -1;
	}
	printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL,
						   argv[2][0] != ' ' ? argv[2] : NULL));
	return 0;
}
