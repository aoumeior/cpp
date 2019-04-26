/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <cmath>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN and divisor == -1)
            return INT_MAX;

        int sign = (static_cast<float>(dividend)) / divisor > 0 ? 1 : -1;
        
        unsigned int dvd = static_cast<unsigned int>(labs(dividend));
        unsigned int dvs = static_cast<unsigned int>(labs(divisor));
        
        unsigned int bit_num[32];
        
        int i = 0;

        unsigned int d = dvs;

        do
        {
            bit_num[i] =  d << i;
            i++;
        }while (bit_num[i-1] < dvd);
        
        i--;

        unsigned int result = 0;
        
        while (dvd >= dvs)
        {
            if (dvd >= bit_num[i])
            {
                dvd -= bit_num[i];
                result += (1 << i);
            }
            else
            {
                i--;
            }
        }
        
        if (result > INT_MAX && sign == 1)
        {
            return INT_MAX;
        }
        return static_cast<int>(result * sign);
    }
};
