/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int sz=que.size();
            Node* p;
            Node* q;//p是前一个节点，q是当前节点
            for (int i=0;i<sz;i++) {
                if (i==0) {
                    p=que.front();//注意最开始是用p，后面才用q。不一样
                    que.pop();
                    q=p;
                } else {
                    q=que.front();
                    que.pop();
                    p->next=q;
                    p=p->next;
                }
                if (q->left)  que.push(q->left);
                if (q->right) que.push(q->right);
            }
        }
        return root;
    }
};
// @lc code=end
