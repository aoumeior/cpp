/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.31%)
 * Total Accepted:    65.1K
 * Total Submissions: 174.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <string>
#include <stack>
#include <cmath>

using namespace std;
class Solution
{
public:
    // 这里传递的是引用还是，一个纯粹的值传递
    // 在测试后好像
    // 效率并没有提升
    bool isValid(const string &str)
    {
        stack<char> s_;
        for (auto c : str)
        {
            if (s_.empty())
            {
                s_.push(c);
                continue;
            }

            if (charValid(s_.top(), c))
            {
                s_.pop();
                continue;
            }

            s_.push(c);
        }
        if (s_.empty())
            return true;
        return false;
    }

    bool charValid(char c, char c1) const
    {
        if (c == '(' and c1 == ')')
        {
            return true;
        }
        if (c == '[' and c1 == ']')
        {
            return true;
        }
        if (c == '{' and c1 == '}')
        {
            return true;
        }

        return false;
    }
};
