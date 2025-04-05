/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public://类外构造函数了也能用
//初始化当默认的
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr) {}//构造函数没有返回体。
    };

    MyLinkedList() {//构造函数
        this->dhead = new ListNode(0);
        this->size = 0;
    }
//看样例。是先写添加操作。
    void addAtHead(int val) {
        //先创建新结点，再插入到表头。基础的链表插入操作。
        ListNode* head = new ListNode(val);//创建新结点
        head->next = dhead->next;//用前驱节点执行插入操作
        dhead->next=head;
        this->size++;
    }

    void addAtTail(int val) {
        //创建一个遍历的指针。遍历+插入
        ListNode* node=new ListNode(val);
        ListNode* p=dhead;
        while (p->next!=nullptr) {//添加操作要用到前驱节点。所以从虚拟头结点开始遍历
            p=p->next;
        }
        p->next=node;//尾插会少一步。
        this->size++;
    }

    void addAtIndex(int index,int val) {
        //后补充的。index范围[0,size-1]，故size可以插入
        if (index<0) index=0;//插到头去
        if (index>size) return;//根据题意，不会插入到链表中
        //添加操作。先创建一个新结点
        ListNode* node = new ListNode(val);
        ListNode* p=dhead;//从前驱节点开始遍历
        while (index--) {
            p=p->next;//写到这就知道要增加边界处理了。在前面增加防越界处理。
        }
        //遍历完了之后p指向要插入位置的前驱。插入操作要两句。
        node->next=p->next;
        p->next=node;
        this->size++;
    }
//查
    int get(int index) {
        //防越界（题中说index范围[0,size-1]）
        if (index>size-1 || index<0) return -1;
        ListNode* p=dhead;//遍历
        while (index--) {
            p=p->next;
        }//找到的是目标节点的前驱节点。
        return p->next->val;

    }
//删
    void deleteAtIndex(int index) {
        //范围同理。
        if (index<0 || index>size-1) return ;
        ListNode* p=dhead;
        while (index--) {
            p=p->next;
        }
        //删除操作有三句
        ListNode* tmp=p->next;
        p->next = p->next->next;
        delete tmp;
        this->size--;
    }



private://只能在类里面访问
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






//一刷
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