/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    int maxDepth(Node* root) {//迭代版
        int depth=0;
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int sz=que.size();
            depth++;
            for (int i=0;i<sz;i++) {//遍历当前层
                Node* cur=que.front(); 
                que.pop();
                for (int j=0;j<cur->children.size();j++) {//遍历子结点，压入下一层
                    if (cur->children[j]) que.push(cur->children[j]);
                }
            }
        }
        return depth;
    }
};
// @lc code=end
// class Solution {
//     public:
    
//         int maxDepth(Node* root) {//递归版
//             if (root==nullptr) return 0;
//             int depth=0;
//             for (int i=0;i<root->children.size();i++) {
//                 depth=max(depth,maxDepth(root->children[i]));
//             }
//             return depth+1;
//         }
//     };
