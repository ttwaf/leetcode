/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            vector<int> vec;
            int sz=que.size();
            for (int i=0;i<sz;i++) {
                Node* cur=que.front();
                que.pop();
                vec.push_back(cur->val);
                int sz2=cur->children.size();
                for (int j=0;j<sz2;j++) {
                    if (cur->children[j]) que.push(cur->children[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

