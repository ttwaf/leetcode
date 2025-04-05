/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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

    int sumOfLeftLeaves(TreeNode* root) {//递归
        if (root==nullptr) return 0;
        int sum=0;
        //左的话加上下面一句判断
        if (root->left && root->left->left==nullptr && root->left->right==nullptr)
            sum=root->left->val;
        //左右中的顺序直接合成一句话
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right)+sum;
    }
};
// @lc code=end

class Solution {
    public:
    
        int sum=0;
        int traversal(TreeNode* cur) {//递归基础版
            //终止条件
            if (cur==nullptr) return 0;
            //左
            int ls=traversal(cur->left);
            if (cur->left && cur->left->left==nullptr && cur->left->right==nullptr) 
                ls=cur->left->val;
            //右
            int rs=traversal(cur->right);
            //中
            int sum=ls+rs;
            return sum;//用中串联起来
        }
    
        int sumOfLeftLeaves(TreeNode* root) {//递归
            if (root==nullptr) return sum;
            sum = traversal(root);
            return sum;
        }
    };

class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root) {//层序迭代
            int sum=0;
            queue<TreeNode*> que;
            if (root) que.push(root);
            while (!que.empty()) {
                int sz=que.size();
                for (int i=0;i<sz;i++) {
                    //中
                    TreeNode* cur=que.front();
                    que.pop();
                    //左
                    if (cur->left) {
                        if (cur->left->left==nullptr && cur->left->right==nullptr)
                            sum+=cur->left->val;
                        que.push(cur->left);
                    }
                    //右
                    if (cur->right) que.push(cur->right);
                }
            }
            return sum;
        }
    };