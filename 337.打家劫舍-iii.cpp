/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        vector<int> res=robb(root);
        return max(res[0],res[1]);
    }

    vector<int> robb(TreeNode* cur) {
        //dp数组直接vector初始化列表硬造
        if (cur==nullptr) return {0,0};
        //左右中.因为要用到左右的返回值。
        vector<int> l=robb(cur->left);
        vector<int> r=robb(cur->right);
        //偷了root，就不偷左右
        int v1=cur->val+l[0]+r[0];
        //不偷root，左右都可偷可不偷
        int v2=max(l[0],l[1])+max(r[0],r[1]);
        return {v2,v1};//注意返回是{不偷，偷了}
    }
};
// @lc code=end

