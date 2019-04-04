
// c++ 11 以后的版本为各个编译器的自定义属性提供了统一的接口
// 详见：
// https : //zh.cppreference.com/w/cpp/language/attributes

#include <iostream>

[[gnu::always_inline]][[gnu::hot]][[gnu::const]][[nodiscard]] inline int
f(); // 声明 f 带四个属性

int main()
{
    std::cout << f() << std::endl;
    return 0;
}

int f() { return 0; }
