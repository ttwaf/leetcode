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
        ListNode* pa=headA;
        ListNode* pb=headB;
        //没有边界判断也没事。一开始如果pa或者pb指向null的话，一样的遍历长度。
        //只是有边界判断的话会快一点。
        while (pa!=pb) {
            if (pa!=nullptr) {//同时走一步
                pa=pa->next;
            } else {
                pa=headB;//换头
            }
            if (pb!=nullptr) {
                pb=pb->next;
            } else {
                pb=headA;
            }
        }
        return pa;
    }
};
// @lc code=end




//一刷
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
            while (pa != pb) {//找到相同节点时停止
                pa = pa == NULL ? headB : pa->next;//pa到尾了？到了的话换头到headb。
                pb = pb == NULL ? headA : pb->next;//没到尾的话两个都往下走一步。
            }
            return pa;
        }
    };