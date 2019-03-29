/*************************************************************************
    > File Name: const_ref_test1.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年03月09日 星期五 19时19分05秒
 ************************************************************************/

#include <iostream>

using namespace std;

// int const = const int , but we need know what is constant value
// because we should use int const

/// @Synopsis max
///
/// @Param a
/// @Param b
///
/// @Returns  int const&
inline int const &max(int const &a, int const &b)
{

	return a < b ? b : a;
}

int main(void)
{

	int a = 1, b = 2;
	std::cout << max(a, b) << std::endl;

	// the 'int const' equal the const int
	int const test1 = 1;
	// test1 = 2;
	const int test2 = 1;
	// test2 = 2;

	// 'const int&' = 'int const' , but mean not
	const int &test3 = 1;
	int const &test4 = 1;

	int const *test5 = &a;
	// read-only variable is not assignable
	//*test5 = 1;
	const int *test7 = &a;
	//*test7 = 1;

	int *const test6 = &a;
	*test6 = 1;
	//test6 = &b;
}
