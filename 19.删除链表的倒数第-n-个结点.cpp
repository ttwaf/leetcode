/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //先造虚拟头结点和双指针
        ListNode* L = new ListNode(0);
        L->next = head;
        ListNode* p = L;
        ListNode* q = L;
        //设共N个节点，p先走n个节点，剩下N-n个节点
        while (n--) {
            p = p->next;
        }
        //若此时p和q同时启动，则最后p指向NULL，走了N+1步（把最后的NULL当成一个节点的话更好理解）,q指向要删除的节点。
        //故让p第一段多走一步，则第二段p和q一起走的时候，q就停在要删除的上一个节点处了
        p=p->next;
        while (p != NULL) {
            p = p->next;
            q = q->next;
        }
        //删除，断链操作
        ListNode* tmp = q->next;
        q->next = q->next->next;
        delete tmp;

        return L->next;
    }
};
// @lc code=end

