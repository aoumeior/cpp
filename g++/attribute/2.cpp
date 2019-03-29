#include <iostream>

struct unpacked_struct
{
      char c;
      int i;
};
// 1,4 =8

struct packed_struct
{
      char c;
      int i;
      struct unpacked_struct s;
} __attribute__((__packed__));
// 1, 4, 8 = 13

int main(int argc, char const *argv[])
{
      std::cout << sizeof(unpacked_struct) << std::endl;
      std::cout << sizeof(packed_struct) << std::endl;
      return 0;
}