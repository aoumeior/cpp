#include <iostream>
#include <type_traits>
#include <string>

// ALIAS TEMPLATE void_t
template <class... _Types>
using void_t = void;

template <class _Ty,
          class = void>
struct _Add_reference
{ // add reference
    using _Lvalue = _Ty;
    using _Rvalue = _Ty;
};

template <class _Ty>
struct _Add_reference<_Ty, void_t<_Ty &>>
{ // add reference
    using _Lvalue = _Ty &;
    using _Rvalue = _Ty &&;
};

template <typename _Ty,
          _Ty _Val>
struct integral_constant
{ // convenient template for integral constant types
    static constexpr _Ty value = _Val;

    using value_type = _Ty;
    using type = integral_constant;

    constexpr operator value_type() const noexcept
    { // return stored value
        return (value);
    }

    constexpr value_type operator()() const noexcept
    { // return stored value
        return (value);
    }
};

template <bool _Val>
using bool_constant = integral_constant<bool, _Val>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

int main()
{

    const bool ret = std::is_move_assignable<int>::value;
    const bool ret_1 = std::is_move_assignable<std::string>::value;

    std::string test_1 = std::string();
    _Add_reference<std::string>::_Lvalue testb = test_1;

    bool ret_2 = __is_assignable(std::string, std::string &);
    bool ret_3 = __is_assignable(void, void);

    bool ret_4 = true_type::value;
}