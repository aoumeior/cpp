## 关于 swap 你必须知道几点：[swap-use-method](./swap-use-method.cpp)
    
    调用名为 swap() ，在所有有该名称且被参数依赖查找找到的函数和定义于头文件 <utility> 的二个模板 std::swap 中，为重载决议所找到的函数。 

    1. swap 不支持查找非限定 swap
    2. 如果想查找非限定 swap 请使用 iter_swap(传入具有指针语义的类型)
    3. swap 是基于移动赋值的

若想使自己的类可以 swap ， 一般的实现方法：

    1. 在外围命名空间定义非成员 swap ，若要求访问非公开数据成员，则它转发成员 swap 
    2. 于类中定义友元函数（此方法从异于 ADL 的名称查找中隐藏类限定交换） 



## [swap-swappable](./swap-swappable.cpp):

    c++17 提供了几个变量模板用于判断两个不同的类型是否满足可 `swapable` 这个能力 我认为是标准 `std::swap` 的扩展，调用非限定的 swap 来进行判断， 如果你想实现一个两个类型的不同交换，则你必须实现自己的 `swap`参数为两个不同类型。 

## reference:

1. [swap](https://zh.cppreference.com/w/cpp/algorithm/swap)
2. [is_swappable](https://zh.cppreference.com/w/cpp/types/is_swappable)
3. [Swappable](https://zh.cppreference.com/w/cpp/named_req/Swappable)

## code(vs2017):


```c++
// swap
template<class _Ty,
	class> inline
	void swap(_Ty& _Left, _Ty& _Right)
		_NOEXCEPT_COND(is_nothrow_move_constructible_v<_Ty>
			&& is_nothrow_move_assignable_v<_Ty>)
	{	// exchange values stored at _Left and _Right
	_Ty _Tmp = _STD move(_Left);
	_Left = _STD move(_Right);
	_Right = _STD move(_Tmp);
	}
```


```c++
// iter_swap
template<class _FwdIt1,
	class _FwdIt2> inline
	void iter_swap(_FwdIt1 _Left, _FwdIt2 _Right)
	{	// swap *_Left and *_Right
	swap(*_Left, *_Right);
	}

```


```c++
// swapable  的帮助类
// std::is_swappable_with, std::is_swappable, std::is_nothrow_swappable_with, std::is_nothrow_swappable

template<class _Ty1,
	class _Ty2,
	class = void>
	struct _Swappable_with_helper
		: false_type
	{	// swap(declval<_Ty1>(), declval<_Ty2>()) is not valid
	};

template<class _Ty1,
	class _Ty2>
	struct _Swappable_with_helper<_Ty1, _Ty2, void_t<decltype(swap(_STD declval<_Ty1>(), _STD declval<_Ty2>()))>>
	// 可以看到这里 swap 前面并没有 _STD 修饰
    	: true_type
	{	// swap(declval<_Ty1>(), declval<_Ty2>()) is valid
	};


```