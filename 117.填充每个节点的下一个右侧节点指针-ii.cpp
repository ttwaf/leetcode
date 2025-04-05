/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
            Node* p;
            Node* q;
            int sz=que.size();
            for (int i=0;i<sz;i++) {
                //设两个指针来遍历这一层
                if (i==0) {
                    p=que.front();
                    que.pop();
                    q=p;
                    // p->next=q;//不能加这句。因为root最后要指向null。没指向null就会tle
                } else {
                    q=que.front();
                    que.pop();
                    p->next=q;
                    p=p->next;
                }
                if (q->left) que.push(q->left);
                if (q->right) que.push(q->right);
            }
        }
        return root;
    }
};
// @lc code=end

