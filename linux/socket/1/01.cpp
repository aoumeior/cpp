/*************************************************************************
    > File Name: 01.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年04月30日 星期一 01时18分39秒
 ************************************************************************/

#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>
#include <fcntl.h>
#define MAXLINE 4096
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;
	if (argc != 2)
	{
		printf("usage: a.out <iPaddress>");
		exit(-1);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("errno= %s\n", strerror(errno));
		exit(-1);
	}

	bzero(&servaddr, sizeof servaddr);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if ((inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0))
	{
		printf("errno = %s\n", strerror(errno));
		exit(-1);
	}

	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof servaddr) < 0)
	{
		printf("connect error: %s\n", strerror(errno));
		exit(-1);
	}

	while ((n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;
		if (fputs(recvline, stdout) == EOF)
		{

			printf("time error");
		}
	}

	if (n < 0)
	{
		printf("read error");
		exit(-1);
	}

	return 0;
}
