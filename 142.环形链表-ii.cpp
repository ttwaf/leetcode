/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        //双指针模拟两个结论
        ListNode* p=head;
        ListNode* q=head;
        //模拟结论一，快指针一次走两格，慢指针一次走一格
        while (q!=nullptr && q->next!=nullptr) {
            q=q->next->next;//走两格
            p=p->next;//走一格
            //模拟结论二，相遇节点和头结点同时出发
            if (p==q) {//如果两个相遇的话，就找到了相遇节点
                ListNode* p1=head;
                ListNode* p2=p;
                while (p1!=p2) {//二者相遇了的话，就一定有环
                    p1=p1->next;
                    p2=p2->next;
                }
                return p1;
            }
        }
        //无环
        return nullptr;
    }
};
// @lc code=end







//一刷
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            //用结论一，p每次走两格，q每次走一格。
            ListNode* p = head;
            ListNode* q = head;
            while (p != NULL && p->next != NULL) {
                //以下两句表一定会相遇
                p = p->next->next;
                q = q->next;
                //相遇了就找起点，用结论二，定义两个新的指针
                if (p == q) {
                    ListNode* p1 = head;
                    ListNode* p2 = p;
                    while (p2 != p1) {
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                    //找到了就可以return
                    return p1;
                }
            }
            //无环则返回NULL
            return NULL;
        }
    };