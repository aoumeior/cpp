/*************************************************************************
    > File Name: asm.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年04月12日 星期四 13时44分21秒
 ************************************************************************/

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    // 会出现段错误
    uint32_t cr0;
    asm volatile("movl %%cr0, %0\n"
                 : "=r"(cr0));
}
