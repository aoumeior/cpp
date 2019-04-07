# 为什么c++会移除throw而改用noexcept?

## 1

答案来自[知乎](https://www.zhihu.com/question/62301046/answer/196906160)：


一个原因是用throw关键字进行异常规范你会发现根本不能确定该怎么写：
比如模板：
```c++
template<class T>
void f( T k )
{
     T x( k );
     x.x();
}
```
比如依赖一些第三方库的函数，你根本不知道该写什么。
而且如果非要列出所有可能抛出的异常，可扩展性很差。
以及，最后，如果抛出了没有在throw中列出来的异常是可以编译通过的，连警告都没有：
```c++
int f () throw (int, double)
{
	throw std::exception ();
}
```
但是用noexcept一般来说就没有上面说的这个问题，知道有没有抛出异常毕竟比知道抛出了什么异常简单得多。

## 2

[stackoverflow](https://stackoverflow.com/questions/88573/should-i-use-an-exception-specifier-in-c/88905#88905) 给出的观点


No.

Here are several examples why:

Template code is **impossible** to write with exception specifications,

```c++
template<class T>
void f( T k )
{
     T x( k );
     x.x();
}
```
The copies might throw, the parameter passing might throw, and `x()` might throw some unknown exception.

Exception-specifications tend to prohibit extensibility.

`virtual void open() throw( FileNotFound );`

might evolve into

`virtual void open() throw( FileNotFound, SocketNotReady, InterprocessObjectNotImplemented, HardwareUnresponsive );`

You could really write that as

`throw( ... )`

The first is not extensible, the second is overambitious and the third is really what you mean, when you write virtual functions.

Legacy code

When you write code which relies on another library, you don't really know what it might do when something goes horribly wrong.

```
int lib_f();

void g() throw( k_too_small_exception )
{ 
   int k = lib_f();
   if( k < 0 ) throw k_too_small_exception();
}
```
`g` will terminate, when `lib_f()` throws. This is (in most cases) not what you really want. std::terminate() should never be called. It is always better to let the application crash with an unhandled exception, from which you can retrieve a stack-trace, than to silently/violently die.

Write code that returns common errors and throws on exceptional occasions.
```c++
Error e = open( "bla.txt" );
if( e == FileNotFound )
    MessageUser( "File bla.txt not found" );
if( e == AccessDenied )
    MessageUser( "Failed to open bla.txt, because we don't have read rights ..." );
if( e != Success )
    MessageUser( "Failed due to some other error, error code = " + itoa( e ) );
try
{
   std::vector<TObj> k( 1000 );
   // ...
}
catch( const bad_alloc& b )
{ 
   MessageUser( "out of memory, exiting process" );
   throw;
}
```
Nevertheless, when your library just throws your own exceptions, you can use exception specifications to state your intent.
### commit
1. in 3, it would technically be std::unexpected not std::terminate. But when this function is called, the default invokes abort(). This generates a core dump. How is this worse than an unhandled exception? (which does basically the same thing)
2. You left out: This effectively wraps everything in a `try {...} catch (<specified exceptions>) { <do whatever> } catch (...) { unexpected();` ] construct, whether or not you want a try block there.
3. An uncatched exception still does stack unwinding. This means destructors will be called. And in those destructors, a lot can be done, like: Resources correctly freed, logs correctly written, other processes will be told the current process is crashing, etc.. To summarize, it's RAII
4. 

## 3
来自 `boost` 的一些看法：(Exception-specification)[https://www.boost.org/development/requirements.html#Exception-specification]

1. 一个愚蠢的编译器会对一个标有异常的函数做出一些令人令人费解的判断：如关闭内敛，增加`try...catch`代码块



## 4
来自另一篇关于异常规范的指导：[A Pragmatic Look at Exception Specifications](http://www.gotw.ca/publications/mill22.htm)

异常规范不参与类型系统，因此你无法定义一个这个样的代码(这是因为异常规范不参与类型的推导与定义)：
```c++

typedef void (*PF)() throw(A,B); // syntax error 

```
但是我们也有其他手段如这种直接定义：
```
void (*PF)() throw(A,B);
```
在 virtual function 的 override 种异常函数参与了类型的推导，子类的异常规范，必须符合父类的异常规范。

## 5
这句话给了我一个我们该如何使用异常的观点（和主题无关）：

A function should always support the strictest guarantee that it can support without penalizing users who don't need it.


## summary

1. 异常规范造成类型上的问题 
2. 模板的出现使得异常规范的抛出类型难以追踪
3. 虚函数也导致抛出的异常规范难以追踪
4. 编译器优化问题
5. 知不知道抛出异常比抛出什么异常更重要
5. *异常的使用使得程序上下文难以追踪（待商榷）*
 
