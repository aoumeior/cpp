# move.cpp

定义于头文件 <utility> 

```c++
template< class T >
typename std::remove_reference<T>::type&& move( T&& t ) noexcept;

template< class T >
constexpr typename std::remove_reference<T>::type&& move( T&& t ) noexcept;
```

std::move 用于指示对象 t 可以“被移动”，即允许从 t 到另一对象的有效率的资源传递。 
特别是， std::move 生成标识其参数 t 的亡值表达式。它**准确地等价于到右值引用类型的 static_cast 。**


move 解决了这样一个问题：
1. 右值在拷贝构造时的效率问题。
2. 由于移动拷贝构造时右值引用变量的名称是左值，而若要绑定到接受右值引用参数的重载，就必须转换到亡值，此乃移动构造函数与移动赋值运算符典型地使用 std::move 的原因： 


## 你必须知道的
**std::move执行到右值的无条件转换。就其本身而言，它没有move任何东西。
std::forward只有在它的参数绑定到一个右值上的时候，它才转换它的参数到一个右值。
std::move和std::forward在运行期都没有做任何事情。**