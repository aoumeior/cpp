#include <iostream>
#include <cassert>

// 变量模板(C++ 14 起)
// 变量模板定义一族变量或静态数据成员。

// 变量模板

template <class T>
constexpr T pi = T(3.1415926535897932385); // 变量模板

template <class T>
constexpr T circular_area(T r) // 函数模板
{
    return pi<T> * r * r; // pi<T> 是变量模板实例化
}

// c++ 11
struct Limits
{
    template <typename T>
    static const T min; // 静态数据成员模板的声明
};
template <typename T>
const T Limits::min = {}; // 静态数据成员模板的定义

// c++ 17
struct Limit
{
    template <typename T>
    static const T min{}; // 静态数据成员模板的声明
};

template <class T>
class X
{
  public:
    static T s; // 类模板的非模板静态数据成员的声明
};
template <class T>
T X<T>::s = 0; // 类模板的非模板静态数据成员的定义

int main()
{
    constexpr float res = circular_area<float>(1.2f);

    static_assert(Limit::min<int> == 0, " ");

    // complime fail, s isn't constent
    "static_assert(X<int>::s == 0, "
    ");";

    assert(X<int>::s == 0);

    static_assert(res - 3 < 4.5f, " ");
}
