#include <type_traits>
/*

 隐式声明的析构函数

*/

// 若不为类类型（ struct 、 class 或 union ）提供用户声明的析构函数，
// 则编译器始终会声明析构函数为其类的 inline public 成员。
// 同任何隐式定义的特殊成员函数，隐式声明的析构函数的异常规定是不抛出，
// 除非任何潜在构造的基类或成员为潜在抛出(C++ 17 起) 隐式定义会直接调用有不同异常规定的函数(C++ 17 前)。
// 实践上，隐式的析构函数为 noexcept ，除非该类为析构函数为 noexcept(false) 的基类或成员所“毒害”。

/*

隐式声明的默认构造函数

*/

// 若不对类类型（struct 、 class 或 union）提供任何用户声明的构造函数，
// 则编译器将始终自动声明作为其类的 inline public 成员的默认构造函数。
class DefaultConstructorDestructorClass
{
};

struct DefaultConstructorDestructorStruct
{
};

union DefaultConstructorDestructorUnion {
};

/*

隐式声明的默认构造函数

*/
// 若存在某个用户声明的构造函数，则用户仍可以关键词 default 强制编译器自动生成本可隐式声明的默认构造函数。

class DefineConstructor
{
public:
  DefineConstructor(const int) {}
};

class CompleGenerateDefaultConstructor
{
public:
  CompleGenerateDefaultConstructor(const int) {}
  CompleGenerateDefaultConstructor() = default;
};

int main()
{
  // constructible
  static_assert(std::is_nothrow_default_constructible<DefaultConstructorDestructorClass>::value, " ");
  static_assert(std::is_nothrow_default_constructible<DefaultConstructorDestructorStruct>::value, " ");
  static_assert(std::is_nothrow_default_constructible<DefaultConstructorDestructorUnion>::value, " ");
  static_assert(std::is_nothrow_default_constructible<CompleGenerateDefaultConstructor>::value, " ");
  // static assert fail
  static_assert(std::is_nothrow_default_constructible<DefineConstructor>::value, " ");

  // destructible
  static_assert(std::is_destructible<DefaultConstructorDestructorClass>::value, " ");
  static_assert(std::is_destructible<DefaultConstructorDestructorStruct>::value, " ");
  static_assert(std::is_destructible<DefaultConstructorDestructorUnion>::value, " ");
  static_assert(std::is_destructible<CompleGenerateDefaultConstructor>::value, " ");
}