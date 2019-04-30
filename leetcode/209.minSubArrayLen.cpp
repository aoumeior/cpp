/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        const int numssize = nums.size();
        int l = 0, r = -1; // nums[l...r] 滑动窗口
        int sum = 0;
        int result = numssize + 1;
        while (l < numssize)
        { // 窗口的左边界在数组范围内,则循环继续

            if (r + 1 < numssize && sum < s)
            {
                r++;
                sum += nums[r];
            }
            else
            { // r已经到头 或者 sum >= s
                sum -= nums[l];
                l++;
            }
            if (sum >= s)
            {
                if ((r - l + 1) < result)
                    result = r - l + 1;
            }
        }
        if (result == numssize + 1)
        {
            return 0;
        }
        return result;
    }
};
