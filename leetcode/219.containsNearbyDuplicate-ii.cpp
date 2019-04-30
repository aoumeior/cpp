/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return false;
        if (k <= 0)
            return false;
        unordered_set<int> record;

        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(nums[i]) != record.end())
            {
                return true;
            }
            record.insert(nums[i]);
            // 保持record中最多有k个元素
            // 因为在下一次循环中会添加一个新元素,使得总共考虑k+1个元素
            if (record.size() == k + 1)
            {
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};
