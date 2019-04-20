/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.10%)
 * Total Accepted:    49.4K
 * Total Submissions: 112K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <utility>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // sustain  标识过程， 在某些情况下 是一个 较大的值
        int sv = INT_MIN;

        // 阶段中最大的过程值
        int rt = INT_MIN;

        for (auto v : nums)
        {
            if (sv <= 0)
            {

                if (v > 0 or sv < v)
                {
                    // adding extre code if you need a maximum-subarray
                    sv = v;
                }
                continue;
            }

            if (v < 0)
            {
                if (rt < sv)
                    rt = sv;
            }
            sv += v;
            // adding extre code if you need a maximum - subarray
        }

        if (sv > rt)
        {
            rt = sv;
            // adding extre code if you need a maximum-subarray
        }
        return rt;
    }
};
