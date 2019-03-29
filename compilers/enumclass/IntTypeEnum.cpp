#include <iostream>

enum class animal : int
{
	cat
};

int main()
{

	animal A;
	A = animal::cat;
	std::cout << static_cast<int>(A) << std::endl;
}