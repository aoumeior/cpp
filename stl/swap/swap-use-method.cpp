#include <vector>
#include <utility>

class IntVector
{
    std::vector<int> v;
    IntVector &operator=(IntVector); // 不可赋值
  public:
    void swap(IntVector &other)
    {
        v.swap(other.v);
    }
};
void swap(IntVector &v1, IntVector &v2)
{
    v1.swap(v2);
}

int main()
{
    IntVector v1, v2;
    std::swap(v1, v2);        // 编译器错误！ std::swap 要求可移动赋值 (MoveAssignable)
    std::iter_swap(&v1, &v2); // OK ：标准库调用非限定 swap()
}