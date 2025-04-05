/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode {
        ListNode* next;
        int val;
        ListNode(int val):val(val),next(nullptr) {}
    };
    //初始化链表
    MyLinkedList() {
        this->dhead=new ListNode(0);//定义虚拟头结点。
        this->size=0;
    }

    
    int get(int index) {//index范围：0到size-1
        //先处理非法的index
        if (index>size-1 || index < 0) return -1;
        ListNode* p=dhead;//替身指针来遍历
        while (index--) {//因为处理过非法的，所以不用担心p->next==NULL的问题
            p=p->next;
        }
        return p->next->val;
    }
    
    void addAtHead(int val) {//就是一个和断开操作对立的连接操作
        ListNode* tmp = new ListNode(val);
        tmp->next = dhead->next;
        dhead->next = tmp;
        size++;//容易忘
    }
    
    //自己写的
    void addAtTail(int val) {
        ListNode* p=dhead;//定义一个用于遍历的指针
        while (p->next != NULL) {
            p=p->next;
        }
        ListNode* tmp = new ListNode(val);
        p->next=tmp;
        size++;
    }

    //index范围：0到size-1。如果等于长度则添加在末尾。
    //自己写的
    void addAtIndex(int index, int val) {
        if (index<0) index=0;
        if (index>size) return;

        ListNode* tmp = new ListNode(val);
        ListNode* p=dhead;//定义一个用于遍历的指针
        while (index--) {
            p=p->next;
        }
        tmp->next=p->next;
        p->next=tmp;
        size++;
    }
    
    void deleteAtIndex(int index) {//index范围：0到size-1
        if (index<0 || index>size-1) return;
        ListNode* p=dhead;
        while (index--) {//由于链表从0开始，而index在0处停下，故不会处理0.故是停在要删的前一个节点处
            p=p->next;
        }
        ListNode* tmp=p->next;
        p->next=tmp->next;
        delete tmp;
        size--;
    }
private:
    ListNode* dhead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

