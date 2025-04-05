/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {//递归dfs

        if (!root) return nullptr;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end

// class Solution {
//     public:
//         TreeNode* invertTree(TreeNode* root) {//层序遍历bfs版
//             queue<TreeNode*> que;
//             if (root) que.push(root);
//             while (!que.empty()) {
//                 int sz=que.size();
//                 for (int i=0;i<sz;i++) {
//                     TreeNode* cur=que.front();
//                     que.pop();
//                     swap(cur->left,cur->right);
//                     if (cur->left) que.push(cur->left);
//                     if (cur->right) que.push(cur->right);
//                 }
//             }
//             return root;
//         }
//     };

// class Solution {
//     public:
//         TreeNode* invertTree(TreeNode* root) {//先序遍历dfs
//             stack<TreeNode*> st;
//             if (root) st.push(root);
//             while (!st.empty()) {
//                 TreeNode* cur=st.top();
//                 st.pop();
//                 swap(cur->left,cur->right);
//                 if (cur->left) st.push(cur->left);
//                 if (cur->right) st.push(cur->right);
//             }
//             return root;
//         }
//     };