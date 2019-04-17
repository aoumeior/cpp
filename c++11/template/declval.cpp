#include <type_traits>

#include <utility>
#include <iostream>

struct Default
{
    int foo() const { return 1; }
};

struct NonDefault
{
    NonDefault(const NonDefault &) {}
    int foo() const { return 1; }
};

int main()
{
    decltype(Default().foo()) n1 = 1; // n1 的类型是 int
    // decltype(NonDefault().foo()) n2 = n1;               // 错误：无默认构造函数

    decltype(std::declval<NonDefault>().foo()) n2 = n1; // n2 的类型是 int
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}