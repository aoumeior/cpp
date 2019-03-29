/*************************************************************************
    > File Name: getpid.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年02月10日 星期六 17时29分36秒
 ************************************************************************/

#include <iostream>
// getpid function
#include <unistd.h>
#include <stdlib.h>
int main(void)
{

    std::cout << " hello world from " << getpid() << std::endl;
    exit(0);
}
