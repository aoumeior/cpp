#include <iostream>

class test
{

  public:
	int _v{};
	int _m{};
};

const test &retTestTempVar()
{

	return test{};
}

void outputTestVar(const test &_1)
{

	std::cout << _1._v << _1._m << std::endl;
}

int main()
{

	const test &_1 = retTestTempVar();
	std::cout << _1._v << _1._m << std::endl;
	outputTestVar(_1);
}