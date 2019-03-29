#include <iostream>

struct TestAligne
{
	short b[3];
} __attribute__((aligned(8)));

struct Test
{
	short b[3];
};
int main()
{
	struct Test A1;
	struct TestAligne A2;
	std::cout << sizeof(A1) << std::endl;
	std::cout << sizeof(A2) << std::endl;
	return 0;
}
