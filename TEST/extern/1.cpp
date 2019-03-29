/*************************************************************************
    > File Name: 1.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年04月20日 星期五 12时04分20秒
 ************************************************************************/

#include <iostream>
#include "e.h"
using namespace std;

extern int othervar;

int main()
{

    test a;
    a.change();

    std::cout << othervar << std::endl;
}
