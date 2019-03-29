#include <utility>
#include <string>
#include <iostream>

// compile info:
// 1. compile: g++ 5.4.0
// 2. operatror system: Ubuntu 5.4.0-6ubuntu1~16.04.11

// res:
// A constructor
// A no move cotor
// A move cotor
// C  move cotor

class Amor
{
  public:
    Amor()
    {
        std::cout << "A constructor" << std::endl;
    }

    Amor(const Amor &)
    {
        std::cout << "A no move cotor" << std::endl;
    }
    Amor(Amor &&)
    {
        std::cout << "A move cotor" << std::endl;
    }

    Amor &operator=(const Amor &other)
    {
        std::cout << "A operator=" << std::endl;
    }

    Amor &operator=(Amor &&other)
    {
        std::cout << "A operator=" << std::endl;
    }
};

class Core
{
  public:
    Core(const Amor &t)
        : str_(t)
    {
    }
    Core(const Core &t)
        : str_(t.str_)
    {
        std::cout << "C  no move cotor" << std::endl;
    }
    // this is the most simplest move cotr
    Core(Core &&t)
        : str_(std::move(t.str_))
    {
        std::cout << "C  move cotor" << std::endl;
    }

    Core &operator=(Core &&other)
    {
        str_ = std::move(other.str_);
        return *this;
    }

  private:
    Amor str_;
};

int main()
{
    // the expr is defined a function
    // Core res_1 (Amor());
    // change it ,as it:
    Core res_1{std::forward<Core>(Core(Amor()))};
}
