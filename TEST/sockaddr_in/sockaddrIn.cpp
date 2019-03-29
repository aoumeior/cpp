/*************************************************************************
    > File Name: sockaddrIn.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年04月21日 星期六 23时02分09秒
 ************************************************************************/

#include <netinet/in.h> // sockaddr sockaddr_in
#include <stdio.h>
#include <sys/socket.h> // bind
#include <stdlib.h>
#include <string.h>	// bzero
#include <arpa/inet.h> //inet_addr

int main()
{

	int sockfd;
	struct sockaddr_in mysock;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&mysock, sizeof mysock);
	mysock.sin_family = AF_INET;
	mysock.sin_port = htonl(800);
	mysock.sin_addr.s_addr = inet_addr("192.168.1.0");
	bind(sockfd, (struct sockaddr *)&mysock, sizeof(struct sockaddr));
	return 0;
}
