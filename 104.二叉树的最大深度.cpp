/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

    int maxDepth(TreeNode* root) {//递归法精简版
        if (root==nullptr) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }//精简版一上来就是调用自身的操作。
    
//         int getDepth(TreeNode* node) {//递归正常版
//             if (node==nullptr) return 0;//遇到空就停下来。
    
//             int ld=getDepth(node->left);
//             int rd=getDepth(node->right);
//             int depth=1+max(ld,rd);
//             return depth;
//         }
    
//         int maxDepth(TreeNode* root) {//递归法
//             return getDepth(root);
//         }//主函数从0开始。进入递归之后从1开始。这个当递归模板吧
};
// @lc code=end

// class Solution {
//     public:
//         int maxDepth(TreeNode* root) {//迭代法
//             queue<TreeNode*> que;
//             int depth=0;
//             if (root) que.push(root);
//             while (!que.empty()) {
//                 int sz=que.size();
//                 for (int i=0;i<sz;i++) {
//                     TreeNode* cur=que.front();
//                     que.pop();
//                     if (cur->left) que.push(cur->left);
//                     if (cur->right) que.push(cur->right);
//                 }
//                 depth++;
//             }
//             return depth;
//         }
//     };

// class Solution {
//     public:
    
//         int getDepth(TreeNode* node) {//递归
//             if (node==nullptr) return 0;//遇到空就停下来。
    
//             int ld=getDepth(node->left);
//             int rd=getDepth(node->right);
//             int depth=1+max(ld,rd);
//             return depth;
//         }
    
//         int maxDepth(TreeNode* root) {//递归法
//             return getDepth(root);
//         }//主函数从0开始。进入递归之后从1开始。这个当递归模板吧
//     };