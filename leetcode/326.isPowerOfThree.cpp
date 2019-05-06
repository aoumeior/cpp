/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // 用到了数论的知识：3 的幂次的质因子只有 3。
        // int 类型，正数范围是 0 - 2^31，
        // 在此范围中允许的最大的 3 的次方数为 319 = 1162261467 ，那么只要看这个数能否被 n 整除即可
        return n > 0 and 1162261467 % n == 0;
    }
};
