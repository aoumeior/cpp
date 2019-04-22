/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.87%)
 * Total Accepted:    49.1K
 * Total Submissions: 224.7K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        /**
         * 
         *  1. sort 
         *  2. two ptr
         * /

        vector<vector<int>> ret;
        int n = nums.size();

        sort(nums.begin(), nums.end()); // 1，2，3

        for (int i = 0; i < n - 2 /* j occupy a postion */
        ; i++)
        {
            int j = i + 1;
            int k = n - 1;
            const int limit = k;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {

                    j++;
                }
                else
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (j < limit and nums[j + 1] == nums[j])
                    {
                        j++;
                    }
                    j++;
                }
            }
            while (i < limit and nums[i + 1] == nums[i])
                i++;
        }

        return ret;
    }
};
