/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* cur=st.top();
            st.pop();
            res.push_back(cur->val);
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }

};
// @lc code=end

    // void traversal(TreeNode* cur,vector<int>& vec) {
    //     //1、递归入口；2、递归出口
    //     if (cur==NULL) return;
    //     traversal(cur->left,vec);
    //     traversal(cur->right,vec);
    //     vec.push_back(cur->val);
    // }


    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }