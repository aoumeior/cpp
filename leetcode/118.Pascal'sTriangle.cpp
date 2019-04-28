/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows < 1)
        {
            return {};
        };
        if (numRows == 1)
        {
            return {{1}};
        };

        if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }

        vector<vector<int>> rt = {{1}, {1, 1}};

        for (int i = 2; i < numRows; i++)
        {
            rt.push_back({});
            rt[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                int l = rt[i - 1].at(j - 1);
                int r = rt[i - 1].at(j);
                int sum = l + r;
                rt[i].push_back(sum);
            }
            rt[i].push_back(1);
        }

        return rt;
    }
};
