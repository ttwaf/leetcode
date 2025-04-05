/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*> st;
        vector<int> res;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* node=st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return res;
    }

};
// @lc code=end

    // //1、确定参数和返回值（入口）
    // void traversal(TreeNode* cur,vector<int>& vec) {
    //     //2、确定终止条件（出口）
    //     if (cur==NULL) return;
    //     //3、确定单层递归的逻辑
    //     vec.push_back(cur->val);
    //     traversal(cur->left,vec);
    //     traversal(cur->right,vec);
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }