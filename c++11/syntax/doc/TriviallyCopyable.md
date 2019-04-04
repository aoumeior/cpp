# TriviallyCopyable

Flie: [../semantic/TriviallyCopyable.cpp](../semantic/TriviallyCopyable.cpp)

`TriviallyCopyable`(平凡拷贝)是  c++ named requirements 对于此要求提供了几个约束

## 关于构造函数和赋值函数
1. Every copy constructor is trivial or deleted 
2. Every move constructor is trivial or deleted 
3. Every copy assignment operator is trivial or deleted 
4. Every move assignment operator is trivial or deleted 
5. at least one copy constructor, move constructor, copy assignment operator, or move  assignment operator is non-deleted（至少一个复制构造函数、移动构造函数、复制赋值运算符或移动赋值运算符未被删除 ）
6. Trivial non-deleted destructor 

## 对于继承上

1. This implies that the class has no virtual functions or virtual base classes. 
2. Scalar types and arrays of TriviallyCopyable objects are TriviallyCopyable as well, as well as the const-qualified (but not volatile-qualified) versions of such types. 


## 兼容性


1. 对于  `volatile` 限定的 被 vs2017 被认为 是非 `TriviallyCopyable`, 在 `g++ 5.7` 版本下 认为是 `TriviallyCopyable` ,应避免使用此判断。
2. 