## std::is_destructible, std::is_trivially_destructible, std::is_nothrow_destructible

```c++
template< class T >
struct is_destructible;

template< class T >
struct is_trivially_destructible;

template< class T >
struct is_nothrow_destructible;
```

file: [../trivial/istrivialdes-0.cpp](../trivial/istrivialdes-0.cpp)


1）若含有 `T` 类型成员对象的虚构结构体拥有非删除的析构函数，则提供等于 `true` 的成员常量 `value` 。对于任何其他类型， `value` 为 `false` 。(C++14 前)

若 T 是引用类型，则提供等于 true 的成员常量 value

若 T 是不完整类型（包含 void ）或函数类型，则 value 等于 false 。 

若 T 是对象类型，则对于等于 std::remove_all_extents<T>::type 的类型 U ，若表达式 

`std::declval<U&>().~U()` 在不求值语境合法，则 `value` 等于 `true` 。否则， `value` 等于 `false` 。 
(C++14 起)

2）同 1），并且 `std::remove_all_extents<T>::type` 要么是非类类型，要么是拥有平凡析构函数的类类型。 

3）同 1） ，但析构函数为 `noexcept` 。 

T 应为完整类型、（可为 cv 限定的） `void` ，或未知边界数组。否则行为未定义。 



被删除的隐式声明的析构函数

file: [../trivial/istrivialdes-0.cpp](../trivial/istrivialdes-1.cpp)

若下列任一条件为真，则类 T 的隐式声明或默认化的析构函数不被定义 (**C++11 前**)定义为被删除 (**C++11 起**)： 
T 有不能析构的非静态数据成员（有被删除或不可访问的析构函数） 
T 有不能析构的直接或虚基类（有被删除或不可访问的析构函数） 
T 是联合体并拥有带非平凡析构函数的变体成员。 
(C++11 起)
隐式声明的析构函数为虚（因为基类有虚析构函数）且解分配函数（ operator delete() ）的查找导致对有歧义、被删除或不可访问函数的调用。 