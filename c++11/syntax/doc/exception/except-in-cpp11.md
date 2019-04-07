## 异常规范的抛出规则

若函数抛出不列于其异常规定的类型的异常，则调用函数 std::unexpected 。函数默认调用 std::terminate ，但它可以为可能调用 std::terminate 或抛出异常的用户提供函数（通过 std::set_unexpected ）替换。若从 std::unexpected 抛出的异常为异常规定所接受，则栈回溯照常持续。若它不被接受，但异常规定允许 std::bad_exception ，则抛出 std::bad_exception 。否则，调用 std::terminate 。 

std::unexpected() 为 C++ 运行时在违背动态异常规定时调用：从其异常规定禁止此类型异常的函数抛出该类型异常。 
亦可从程序直接调用 std::unexpected() 。 
任一情况下， std::unexpected 调用当前安装的 std::unexpected_handler 。默认的 std::unexpected_handler 调用 std::terminate 。 


## 潜在异常
每个函数 `f` ，指向函数的指针 `pf` ，与指向成员函数的指针 `pmf` 拥有一个“潜在异常集合”，它由可能抛出的类型构成。所有类型的集合指示可能抛出所有异常。此集合定义如下： 
1) 若 `f` 、 `pf` 或 `pmf` 的声明使用 `throw()`(弃用) 或 `noexcept` ，则集合为空。
2) 否则，若 `f` 、 `pf` 或 `pmf` 使用动态异常规定(弃用)，则集合由列于该规定的所有类型组成
3) 否则，集合是所有类型的集合
注意：对于隐式声明的特殊成员函数（构造函数、赋值运算符及析构函数），及对于继承的构造函数，潜在异常的集合是它们会调用的所有函数的潜在异常集合的并集：非变体非静态数据成员、直接基类及适当场合的虚基类的构造函数/赋值运算符/析构函数（还包括默认参数表达式） 

每个表达式 `e` 拥有潜在异常集合，它是所有 `e` 的立即子表达式（包含默认参数表达式）的潜在异常集合的并集，与下列取决于 e 的形式其他集合的并： 
1) 若 `e` 是一个函数调用表达式，且 
函数以 `id` 表达式指名（直接或作为成员访问一部分或作为指向成员指针表达式），则将该具名函数的潜在异常集合添加到列表。 
若函数以 `noexcept` 函数类型的表达式指名，或以指向 noexcept 函数的指针类型的表达式指名，则该集合为空 
否则，该集合是所有类型的集合
2) 若 `e` 隐式调用函数（是运算符表达式且该运算符被重载，是 new 表达式且重载了其分配函数，或是完整表达式且调用了临时量的析构函数），则该集合是该函数的集合。
3) 若 `e` 是一个 `throw` 表达式，则该集合是将以其运算数初始化的异常，或对于重抛出表达式（无运算数者）是所有异常的集合
4) 若 `e` 是对到多态类型引用的 `dynamic_cast` ，则该集合由 `std::bad_cast` 组成
5) 若 `e` 是应用到多态泛左值的 `typeid` ，则该集合由 `std::bad_typeid` 组成
6) 若 `e`是一个拥有非常量大小的 `new` 表达式，则集合由 `std::bad_array_new_length` 组成

```c++
void f() throw(int);  // f() 的集合是“ int ”
void g();             // g() 的集合是所有类型的集合
struct A { A(); };    // “ new A ”的集合是所有类型的集合
struct B { B() noexcept; }; // “ B() ”的集合为空
struct D() { D() throw (double); }; // “ new D ”的集合是所有类型的集合
```
所有隐式声明的成员函数（及继承的构造函数）拥有异常规定，选择如下： 
若潜在异常为类型的全集，则隐式异常规定为 noexcept(false) 。 
否则，若潜在异常的集合非空，则隐式异常规定列出每个来自该集合的类型 
否则，隐式异常规定为 noexcept(true) 且函数是“ noexcept 函数” 

```c++

struct A
{
    A(int = (A(5), 0)) noexcept;
    A(const A&) throw();
    A(A&&) throw();
    ~A() throw(X);
};
struct B
{
    B() throw();
    B(const B&) = default; // 异常规定是“ noexcept(true) ”
    B(B&&, int = (throw Y(), 0)) noexcept;
    ~B() throw(Y);
};
int n = 7;
struct D
    : public A, public B
{
    int * p = new (std::nothrow) int[n];
    // D 拥有下列隐式声明的成员：
    // D::D() throw(X, std::bad_array_new_length);
    // D::D(const D&) noexcept(true);
    // D::D(D&&) throw(Y);
    // D::~D() throw(X, Y);
};

```









[[1.动态异常规定]](https://zh.cppreference.com/w/cpp/language/except_spec)