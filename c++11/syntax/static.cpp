#include <iostream>

struct First
{
    // 事实上 vs2017 和 g++ 5.4 并不支持支持次
    //  内联静态变量的类内定义
    inline static int n = 1; // c++17 起
};

struct Second
{
    const static int n = 1;
    const static int m{2}; // C++11 起 支持
    const static int k;
};
const int Second::k = 3;

int main()
{
    Second f;
    // compile fail
    std::cout << f.n << std::endl;
}