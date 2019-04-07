#include <type_traits>
#include <cassert>

// g++ -std=c++17 -O istrivialdes-0.cpp

class NoHasDestroy
{
  private:
    ~NoHasDestroy() throw() = default;
  public:
    int testa_;
};


class TestHasDefaultDestroy
{

    public:
        NoHasDestroy testa_;
};

class HasTrivialDestroy
{
  public:
    ~HasTrivialDestroy() throw() = default;
  public:
    int testa_;
};

class HasUntrivialDestroy
{
  public:
    ~HasUntrivialDestroy() throw() {}
  public:
    int testa_;
};

int main ()
{
    // pod
    static_assert(std::is_destructible<int>::value," ");
    static_assert(std::is_trivially_destructible<int>::value," ");
    static_assert(std::is_nothrow_destructible<int>::value," ");

    // un-integrity type
    // res: fail
    static_assert(std::is_destructible<void>::value," ");
    static_assert(std::is_trivially_destructible<void>::value," ");
    static_assert(std::is_nothrow_destructible<void>::value," ");

    // privately-owned destroy
    // res: fail
    static_assert(std::is_destructible<NoHasDestroy>::value," ");
    static_assert(std::is_trivially_destructible<NoHasDestroy>::value," ");
    static_assert(std::is_nothrow_destructible<NoHasDestroy>::value," ");


    //  privately-owned destroy type that reference
    static_assert(std::is_destructible<NoHasDestroy&>::value," ");
    static_assert(std::is_trivially_destructible<NoHasDestroy&>::value," ");
    static_assert(std::is_nothrow_destructible<NoHasDestroy&>::value," ");

    // The type of a member that has a private destructor
    // res: fail
    static_assert(std::is_destructible<TestHasDefaultDestroy>::value," ");
    static_assert(std::is_trivially_destructible<TestHasDefaultDestroy>::value," ");
    static_assert(std::is_nothrow_destructible<TestHasDefaultDestroy>::value," ");

    //  with a trivial destructor
    static_assert(std::is_destructible<HasTrivialDestroy>::value, " ");
    static_assert(std::is_trivially_destructible<HasTrivialDestroy>::value, " ");
    static_assert(std::is_nothrow_destructible<HasTrivialDestroy>::value, " ");
    
    // 
    static_assert(std::is_destructible<HasUntrivialDestroy>::value, " ");
    static_assert(std::is_nothrow_destructible<HasUntrivialDestroy>::value, " ");


    // c v
    static_assert(std::is_destructible<const HasTrivialDestroy>::value, " ");
    static_assert(std::is_trivially_destructible<const HasTrivialDestroy>::value, " ");
    static_assert(std::is_nothrow_destructible<const HasTrivialDestroy>::value, " ");
    static_assert(std::is_destructible<volatile HasTrivialDestroy>::value, " ");
    static_assert(std::is_trivially_destructible<volatile HasTrivialDestroy>::value, " ");
    static_assert(std::is_nothrow_destructible<volatile HasTrivialDestroy>::value, " ");
}