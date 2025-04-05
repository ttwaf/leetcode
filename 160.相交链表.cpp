/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //定义两个用于遍历的双指针
        ListNode* pa = headA;
        ListNode* pb = headB;

        //排除while死循环的情况
        if (pa == NULL || pb == NULL) {
            return NULL;
        }
        //最后会在相交节点处相遇或同时指向NULL。效果实际上相当于代码随想录里的对齐后遍历。
        while (pa != pb) {
            pa = pa == NULL ? headB : pa->next;
            pb = pb == NULL ? headA : pb->next;
        }
        return pa;
    }
};
// @lc code=end

