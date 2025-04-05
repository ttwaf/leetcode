/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    
    ListNode* removeElements(ListNode* head, int val) {
        //1、构造虚拟头结点指向head
        ListNode* dhead = new ListNode(0);//我理解new就相当于创建指针+malloc
        dhead->next=head;
        //2、指针遍历链表，断链
        ListNode* p=dhead;
        while (p->next != nullptr) {//因为删除需要用到前一个节点。所以while条件如此
            if (p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        head=dhead->next;//一定要加这一句。因为头结点可能变了。要返回新的头结点。
        return head;
    }
};
// @lc code=end













//一刷
class Solution {
public:
    
    ListNode* removeElements(ListNode* head, int val) {
        //自己构造一个虚拟头结点指向head
        ListNode* L = new ListNode(0);//new后面的是构造函数。看题目注释
        L->next = head;//虚拟头结点指向head
        
        ListNode* p=L;//用一个p指针来遍历链表
        while (p->next != NULL)//找要删除的节点的前一个节点
        {
            if (p->next->val==val) {//基础断链操作。
                ListNode* tmp = p->next;
                p->next=p->next->next;
                delete tmp;
            } else {
                p=p->next;
            }
        }
        head = L->next;
        delete L;
        return head;
    }
};










// ListNode* removeElements(ListNode* head, int val) {
//     while (head!=nullptr && head->val==val) {//头结点没有前驱节点
//         ListNode* tmp=head;
//         head=head->next;
//         delete tmp;
//     }


//     ListNode* node = head;
//     while (node!=nullptr && node->next!=nullptr) {
//         if (node->next->val==val) {//这一整套操作直接叫断链吧
//             ListNode* tmp=node->next;
//             node->next=tmp->next;
//             delete tmp;
//         }
//         else node=node->next;//不能马上跳到后继节点，可能需要连续删除
//     }
//     return head;
// }