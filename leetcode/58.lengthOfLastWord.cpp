/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (29.41%)
 * Total Accepted:    23.4K
 * Total Submissions: 79.5K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int rt = 0;
        find_if(s.rbegin(), s.rend(), [&](char c) {
            if (rt == 0 and c == ' ')
                return false;

            if (c != ' ')
            {
                rt++;
                return false;
            }
            return true;
        });

        return rt;
    }
};
