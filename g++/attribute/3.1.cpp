#include <iostream>
#include <stdlib.h>

int test(int i) __attribute__((noreturn));

int main(int argc, char const *argv[])
{

	test(1);
	/* code */
	return 0;
}

// complie flag g++ -Wall 3.cpp

int test(int i)
{
	if (i > 1)
	{
		exit(0);
	}
	else
	{

		exit(0);
		/* code */
	}
}