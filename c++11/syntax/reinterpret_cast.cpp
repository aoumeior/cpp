struct S1
{
    int a;
} s1;
struct S2
{
    int a;

  private:
    int b;
} s2; // 非标准布局
union U {
    int a;
    double b;
} u = {0};
int arr[2];

int main()
{
    int *p1 = reinterpret_cast<int *>(&s1); // p1 的值为“指向 s1.a 的指针”
                                            // 因为 s1.a 与 s1 为指针可互转换

    int *p2 = reinterpret_cast<int *>(&s2); // reinterpret_cast 不更改 p2 的值为“指向 s2 的指针”。

    int *p3 = reinterpret_cast<int *>(&u); // p3 的值为“指向 u.a 的指针”： u.a 与 u 指针可互转换

    double *p4 = reinterpret_cast<double *>(p3); // p4 的指针为“指向 u.b 的指针”： u.a 与 u.b
                                                 // 指针可互转换，因为都与 u 指针可互转换

    int *p5 = reinterpret_cast<int *>(&arr); // reinterpret_cast 不更改 p5 的值为“指向 arr 的指针”
}