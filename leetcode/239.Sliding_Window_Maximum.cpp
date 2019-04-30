/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <deque>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

// √ Accepted
// √ 18 / 18 cases passed(84 ms)
// √ Your runtime beats 90.04 % of cpp submissions
// √ Your memory usage beats 97.85 % of cpp submissions(12.7 MB)

class Solution
{
public:
    vector<int>
    maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty())
            return {};
        if (k == 1)
            return nums;

        auto count = nums.size();
        vector<int> rt;
        rt.reserve(count - k + 1);
        deque<int> de;

        for (int i = 0; i < count; i++)
        {
            //在尾部添加元素，并保证左边元素都比尾部大
            while (!de.empty() && nums[de.back()] < nums[i])
            {
                de.pop_back();
            }

            de.push_back(i);
            //在头部移除元素
            if (de.front() == i - k)
            {
                de.pop_front();
            }
            //输出结果
            if (i >= k - 1)
            {
                rt.push_back(nums[de.front()]);
            }
        }

        return rt;
    }
};
