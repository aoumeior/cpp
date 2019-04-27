/*
 * @lc app = leorcode.cn id = 19 lang = cpp // // // // // // // // // //
        * *
    [19] 删除链表的倒数第N个节点
        * /
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };

#include <vector>

using namespace std;

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        
        if(head->next == NULL) return NULL;
        
        vector<ListNode*> l_;
        l_.reserve(8);

        ListNode* t = head;
        
        do
        {
            l_.push_back(t);
            t = t->next;
        }while(t != NULL);

        
        auto count = l_.size();
        
        if(count - n  == 0)
        {
            delete l_[0];
            return l_[1];
        }

        if(n == 1)
        {   
            l_[count- 2]->next = NULL;
            delete l_[count- 1];
            return head;
        }

        l_[count-n-1]->next = l_[count-n]->next;

        delete l_[count-n];

        return head;
    }
};

