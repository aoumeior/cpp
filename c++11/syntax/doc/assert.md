# assert


1. 宏 `assert` 的定义依赖于标准库不定义的另一个宏 **`NDEBUG`**。 
2. 若在包含了 `<cassert>` 的源代码中一点定义 `NDEBUG` 为宏名，则 `assert` 不做任何事。 
3. 若不定义 `NDEBUG` ，则 `assert` 将其参数（必须拥有标量类型）与零比较相等。若相等，则 `assert `在标准错误输出上输出实现指定的诊断信息，并调用 std::abort 。诊断信息要求包含 expression 的文本，还有标准宏 `__FILE__` 、 `__LINE__` 以及标准变量 `__func__` 的值。 

NOTIC:

**因为 assert 是仿函数宏，在 condition 中未被括号保护的逗号都被转译成宏参数的分隔符。这种逗号常能在模板参数列表和列表初始化中找到**：

```c++

assert(c == std::complex<double>{0, 0}); // 错误
assert((c == std::complex<double>{0, 0})); // OK

```

# static_assert

支持： c++11起

原型：
```c++

static_assert ( bool_constexpr , message ) 

```

`static_assert`在c++11与 c++17所表现不同之处在于 message 参数为可选的


一个例子：

```c++

template <class T>
void swap(T& a, T& b)
{
    static_assert(std::is_copy_constructible<T>::value,
                  "Swap requires copying");
    static_assert(std::is_nothrow_copy_constructible<T>::value
               && std::is_nothrow_copy_assignable<T>::value,
                  "Swap requires nothrow copy/assign");
    auto c = b;
    b = a;
    a = c;
}

```
