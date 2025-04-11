/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        //链表题很多都是直接模拟。
        ListNode* dhead = new ListNode();//虚拟头结点
        dhead->next = head;
        ListNode* p = dhead;//遍历的指针
        //两个两个交换。虚拟头结点是0，原顺序0123变为0213
        while (p->next!=nullptr && p->next->next!=nullptr) {//条件内要用到后续两个连续节点.循环体内甚至要用到后第三个
            ListNode* tmp1 = p->next;
            ListNode* tmp2 = p->next->next->next;//用第三个。为null就为null也无妨
            //阶梯状理顺序
            p->next = p->next->next;//0->2
            p->next->next = tmp1;//2->1,但1经过第一步就没了。所以要提前保留
            p->next->next->next = tmp2;//结尾保持指向第三个

            p=p->next->next;//跳两个
            
        }
        return dhead->next;

    }
};
// @lc code=end
//一刷
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            //先定义一个虚拟头结点指向头结点
            ListNode* L = new ListNode(0);
            L->next = head;
            ListNode* p = L;//定义一个遍历的指针
            //一次走两个节点。
            while (p->next != NULL && p->next->next != NULL) {
                //定义临时节点来保存。可以先把步骤写完再回来定义。要用到什么临时节点就定义什么临时节点。
                ListNode* tmp = p->next;
                ListNode* tmp1 = p->next->next->next;
                
                //开始三个步骤:0123变为0213
                p->next = p->next->next;//0指向2
                p->next->next = tmp;//2指向1
                p->next->next->next = tmp1;//1指向3
    
                p = p->next->next;//走两个节点
            }
            return L->next;//没删虚拟头结点。
        }
    };