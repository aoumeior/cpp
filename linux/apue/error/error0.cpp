/*************************************************************************
    > File Name: error0.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月10日 星期六 18时24分23秒
 ************************************************************************/

// 定义errno 和 可以赋予它的各种常数，常数都以E开头
// 第一条规则是： 如果没有出错，其数值不会被一个例程清除。
// 因此仅当函数的返回值指明出错时候，才检验其数值
// 第二条，任何函数不能将 errno 数值 清0, errno.h 中所有常数都不为0
#include <errno.h>

// 定义两个函数帮助打印出错信息，
// char* strerror (int )
#include <string.h>
// void perror (const char* msg)
#include <stdio.h>

int main(int agrc, char **argv)
{
	//EACCES : access 应该是权限错误
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);

	return 0;
}
