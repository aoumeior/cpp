// __attribute__((const)) invail

#include <stdio.h>

int __attribute__((const)) add(int x)
{
    printf("%s(%d)\n", __FUNCTION__, x);
    return x + 1;
}

int add2(int x)
{
    printf("%s(%d)\n", __FUNCTION__, x);
    return x + 1;
}

int main(int argc, char *argv[])
{
    int i, j;

    i = add(1);
    j = add(10);

    printf("%d %d\n", i, j);

    i = add2(2);
    j = add2(10);

    printf("%d %d\n", i, j);

    return 0;
}