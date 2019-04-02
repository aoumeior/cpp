#

文件： [is_move_assignable.cpp](../is_move_assignable.cpp)

`is_move_assignable`用来判断是否具有移动赋值函数

`is_move_assignable` 继承自 `bool_constant`

`bool_constant` 是用于存储类型和`bool`类型的容器

`bool_constant` 需要传入两个参数一个是 布尔类型的 `TRUE,FALSE`，一个是需要存储的类型

`__is_assignable` 由编译器实现是一个传入类型的函数，返回`bool`值，在`is_move_assignable`实现中`bool_constant`第一个参数为`__is_assignable`并传入了一个增加左值引用的模板。

```c++

template<class _Ty>
	struct is_move_assignable
		: bool_constant<__is_assignable(add_lvalue_reference_t<_Ty>, _Ty)>
	{	// determine whether _Ty has a move assignment operator
	};

```

**`bool_constant` 是基本类型模板封装的一个偏特化**

类型定义如下：

```c++

template<bool _Val>
	using bool_constant = integral_constant<bool, _Val>;

```

**由于 bool 类型可枚举 编辑器提供两个预定义类型**

```c++

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

```

**intergral_constant 是一个 integral constant types 的封装用于提供编译期常量的计算**

提供类编译期类型转换函数，编译期函数调用的重载
1. 存储类型
2. 存储编译器常量

定义如下：
``` c++

template<class _Ty,
	_Ty _Val>
	struct integral_constant
	{	// convenient template for integral constant types
	static constexpr _Ty value = _Val;

	using value_type = _Ty;
	using type = integral_constant;

	constexpr operator value_type() const noexcept
		{	// return stored value
		return (value);
		}

	_NODISCARD constexpr value_type operator()() const noexcept
		{	// return stored value
		return (value);
		}
	};


```




在`add_lvalue_reference_t`有几点需要注意：

1. void 不被支持也不被允许增加左值引用
2. 在 add_lvalue_reference_t 中式通过 SFINE 来在编译器决策是否为 void 类型