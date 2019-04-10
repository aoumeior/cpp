#include <algorithm>
#include <utility>
#include <type_traits>

int main()
{

    // 我在 vs2017 g++ 5.4 都不能编译通过
    // c++17
    static_assert((std::is_nothrow_swappable_with<int[], int[]>::value), " ");
    int a[11] = {1};
    int b[11] = {2};
    std::swap(a, b);
}