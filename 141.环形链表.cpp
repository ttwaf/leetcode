/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //双指针
        ListNode* p=head;
        ListNode* q=head;
        //直接用结论一
        while (q!=nullptr && q->next!=nullptr) {
            q=q->next->next;
            p=p->next;
            if (p==q) return true;
        }
        return false;
    }
};
// @lc code=end

