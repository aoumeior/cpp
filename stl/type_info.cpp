#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>

// 有效的类型-值映射的示例。

struct A
{
    virtual ~A() = default;
};

struct B : A {};

struct C : A {};

using namespace std;
int main ()
{
    unordered_map<type_index,string> type_name;

    type_name[type_index(typeid(int))] = "int";
    type_name[type_index(typeid(double))] = "double";
    type_name[type_index(typeid(A))] = "A";
    type_name[type_index(typeid(B))] = "B";
    type_name[type_index(typeid(C))] = "C";

    int i;
    double d;
    A a;

      // 注意我们正在存储指向类型 A 的指针
    unique_ptr<A> b(new B);
    unique_ptr<A> c(new C);

    cout<< "i is  " << type_name[typeid(i)] << endl;
    cout<< "d is  " << type_name[typeid(d)] << endl;
    cout<< "a is  " << type_name[typeid(a)] << endl;
    cout<< "b is  " << type_name[typeid(*b)] << endl;
    cout<< "c is  " << type_name[typeid(*c)] << endl;

    return 0;
}