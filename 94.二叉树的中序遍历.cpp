/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        // if (root) st.push(root);//不在开头预存，因为后面要一直预存。所以放到后面一起定义
        TreeNode* cur=root;
        while (cur!=NULL || !st.empty()) {//左子树和右子树共用一个出口
            if (cur!=NULL) {//一直预存
                st.push(cur);
                cur=cur->left;
            } else {
                cur=st.top();//退一步
                st.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }

};

// @lc code=end

// class Solution {
// public:

//     void traversal(TreeNode* cur, vector<int>& vec) {
//         //1、递归入口；2、递归出口
//         if (cur==NULL) return;
//         //3、单层递归逻辑
//         traversal(cur->left,vec);
//         vec.push_back(cur->val);
//         traversal(cur->right,vec);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traversal(root,res);
//         return res;
//     }
// };