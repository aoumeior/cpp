/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.99%)
 * Total Accepted:    28.4K
 * Total Submissions: 61.7K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> foreachset;
        vector<int> judgeset;

        foreachset.push(root->left);
        foreachset.push(root->right);

        size_t currentnodesize = 0;
        while (true)
        {
            judgeset.clear();
            int a = 0;
            currentnodesize = foreachset.size();
            for (size_t i = 1; i <= currentnodesize; i++)
            {
                auto r = foreachset.front();
                foreachset.pop();
                if (r != NULL)
                {
                    a = 1;
                    judgeset.push_back(r->val);
                    foreachset.push(r->left);
                    foreachset.push(r->right);
                }
                else
                {
                    judgeset.push_back(-1000);
                    foreachset.push(NULL);
                    foreachset.push(NULL);
                }
            }

            auto rt = check(judgeset);
            if (rt == true and a == 0)
            {
                return true;
            }

            if (rt == false)
                return false;
        }
    }

private:
    bool check(const vector<int> &v) const
    {
        size_t e = v.size(); //4
        size_t i = 1;        // 1
        size_t j = e;        // 4
        for (; i <= e / 2; i++, j--)
        {
            if (v[i - 1] != v[j - 1])
            {
                return false;
            }
        }
        return true;
    }
};
