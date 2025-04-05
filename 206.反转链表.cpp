/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //定义双指针来遍历。一个指向翻转的头，一个指向翻转的尾。
        ListNode* p=head;//从头开始翻转
        ListNode* q=NULL;
        ListNode* tmp;//保存节点的指针
        while (p) {//条件为p->next!=NULL时是找目标节点的前一个节点。p则是直接找目标节点
            tmp=p->next;//保存下一节点
            p->next=q;//翻转更新
            q=p;
            p=tmp;
        }
        return q;
    }
};
// @lc code=end

