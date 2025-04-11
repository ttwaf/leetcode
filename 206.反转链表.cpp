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
    }
};
// @lc code=end

class Solution {//二刷，递归写法
    public:
    
        ListNode* reverse(ListNode* pre,ListNode* cur) {
            if (cur==nullptr) return pre;//cur到空，pre到尾，返回头结点。
    
            ListNode* tmp=cur->next;
            cur->next=pre;
            return reverse(cur,tmp);//相当于快慢指针前移的操作。
            //即相当于
            // pre=cur;//慢指针前进
            // cur=tmp;//快指针前进
        }
    
        ListNode* reverseList(ListNode* head) {
            return reverse(nullptr,head);//相当于传入pre,cur
        }
    };

class Solution {//二刷，双指针写法
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* pre=nullptr;//前一个节点，慢指针
            ListNode* cur=head;//当前节点，快指针。
            while (cur) {//快指针走到空。
                ListNode* tmp=cur->next;//暂存下一个
                cur->next=pre;//反转
                pre=cur;//慢指针前进
                cur=tmp;//快指针前进
            }//最后慢指针走到尾
            return pre;
        }
    };


//一刷
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