/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

    int getDepth(TreeNode* root) {
        if (root==nullptr) return 0;//
        //左
        int ld=getDepth(root->left);
        if (ld==-1) return -1;//这是在左右中写了之后再写的。
        //右
        int rd=getDepth(root->right);
        if (rd==-1) return -1;//这是在左右中写了之后再写的。
        //中
        // int res;
        // if (abs(ld-rd)>1) res=-1;
        // else res=max(ld,rd)+1;//以左右最大的高度+1为整个子树的高度
        // return res;

        //用三元运算符简化条件判断
        return abs(ld-rd)>1 ? -1 : max(ld,rd)+1;
    }

    bool isBalanced(TreeNode* root) {
        // int res=getDepth(root);
        // if (res==-1) return false;
        // else return true;

        //用三元运算符简化条件判断
        return getDepth(root)==-1 ? false : true;
    }
};
// @lc code=end

