/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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

    TreeNode* traversal(vector<int>& nums, int lft, int rig) {
        //终止条件。左闭右开相等时为空节点
        if (lft==rig) return nullptr;
        //中
        //构造节点，只需要维护最大值即可
        int m=INT_MIN;
        int idx=0;
        for (int i=lft;i<rig;i++) {
            if (nums[i]>m) {
                m=nums[i];
                idx=i;
            }
        }
        TreeNode* root=new TreeNode(m);
        //左[lft,m),m,[m+1,rig)
        root->left=traversal(nums,lft,idx);
        //右
        root->right=traversal(nums,idx+1,rig);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums,0,nums.size());
    }
};
// @lc code=end

