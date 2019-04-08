#include <type_traits>
#include <cassert>
#include <string>
// 被删除的隐式声明的析构函数
//  1. T 有不能析构的非静态数据成员（有被删除或不可访问的析构函数）
class NoHasDestroy
{
private:
  ~NoHasDestroy() throw() = default;

public:
  int testa_;
};

class TestHasDefaultDestroy
{

public:
  NoHasDestroy testa_;
};

// 2. T 有不能析构的直接或虚基类（有被删除或不可访问的析构函数）
class VirtualBaseClass
{

public:
  ~VirtualBaseClass() = delete;

public:
  int mumber_;
};

class TestInherit : virtual VirtualBaseClass
{
};

// 3. T 是联合体并拥有带非平凡析构函数的变体成员。(C++11 起)
union HasUntrivialMumber {
  std::string str_;
};

union HastrivialMumber {
  int val_;
};

// 4. 隐式声明的析构函数为虚（因为基类有虚析构函数）且解分配函数（ operator delete() ）的查找导致对有歧义、被删除或不可访问函数的调用。

/*

  I don‘t know how finish it on 4th condition

*/

int main()
{
  // istrivialdes-1.cpp: In function ‘int main()’:
  // istrivialdes - 1.cpp : 44 : 3 : error : static assertion failed : static_assert(std::is_trivially_destructible<TestHasDefaultDestroy>::value, " ");
  // istrivialdes - 1.cpp : 45 : 3 : error : static assertion failed : static_assert(std::is_trivially_destructible<TestInherit>::value, " ");
  // istrivialdes - 1.cpp : 46 : 3 : error : static assertion failed : static_assert(std::is_trivially_destructible<HasUntrivialMumber>::value, " ");
  static_assert(std::is_trivially_destructible<TestHasDefaultDestroy>::value, " ");
  static_assert(std::is_trivially_destructible<TestInherit>::value, " ");
  static_assert(std::is_trivially_destructible<HasUntrivialMumber>::value, " ");

  // res: true
  static_assert(std::is_trivially_destructible<HastrivialMumber>::value, " ");
}
