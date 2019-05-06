/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
class Solution
{
public:
    // 先加入左括号，然后在右括号比左括号少，即合法的情况下，再加入右括号
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string temp;
        temp.reserve(20);
        generateParenthesisDFS(n, 0, 0, temp, res);
        return res;
    }

    void generateParenthesisDFS(int n, int left, int right, string &temp, vector<string> &res)
    {
        if (left < n)
        {
            temp.push_back('(');
            generateParenthesisDFS(n, left + 1, right, temp, res);
            temp.pop_back();
        }

        if (right < left) //避免出现右括号比左括号多的情况。
        {
            temp.push_back(')');
            generateParenthesisDFS(n, left, right + 1, temp, res);
            temp.pop_back();
        }
        if (temp.size() == n * 2)
            res.push_back(temp);
    }
};
