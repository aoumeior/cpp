#include <random>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    std::mt19937 rng; // 默认构造，以固定的种子播种
    std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                    5, std::ref(rng));
    std::cout << '\n';
}