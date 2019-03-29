/*************************************************************************
    > File Name: SySbacktracefunction.cpp
    > Author: aoumeior
    > Mail: aoumeior@outlook.com 
    > Created Time: 2018年04月10日 星期二 16时44分52秒
 ************************************************************************/

#include <execinfo.h>
#include <exception>
#include <string>
#include <memory.h>
#include <stdio.h>

using namespace std;
class Exception : std::exception
{

public:
  explicit Exception(const char *what);
  explicit Exception(const string &what);
  virtual ~Exception() throw();
  virtual const char *what() const throw();
  const char *stackTrace() const throw();

private:
  void fillStackTrace();

  string message_;
  // 用于栈追踪
  string stack_;
};

Exception::Exception(const char *msg)
    : message_(msg)
{
  // 用于栈追踪的初始化
  fillStackTrace();
}

Exception::Exception(const string &msg)
    : message_(msg)
{
  // 用于栈追踪的初始化
  fillStackTrace();
}

Exception::~Exception() throw()
{
}

const char *Exception::what() const throw()
{
  return message_.c_str();
}

const char *Exception::stackTrace() const throw()
{
  return stack_.c_str();
}

void Exception::fillStackTrace()
{
  const int len = 200;
  void *buffer[len];
  // #include <execinfo.h>
  // 用于获取程序中的当前函数的回溯信息，即一系列的函数关系
  int nptrs = ::backtrace(buffer, len);
  char **strings = ::backtrace_symbols(buffer, nptrs);
  if (strings)
  {
    for (int i = 0; i < nptrs; ++i)
    {
      // TODO demangle funcion name with abi::__cxa_demangle
      stack_.append(strings[i]);
      stack_.push_back('\n');
    }
    free(strings);
  }
}

void callException()
{

  throw Exception("over");
}

int main()
{
  try
  {
    callException();
  }
  catch (Exception &e)
  {

    printf("%s\n", e.what());

    printf("%s", e.stackTrace());
  }
}
