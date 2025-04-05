/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {//迭代版
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val>p->val && root->val>q->val) root=root->left;
            else if (root->val<p->val && root->val<q->val) root=root->right;
            else return root;//找得到
        }
        return nullptr;//找不到
    }
};
// @lc code=end

class Solution {//递归版
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root->val>p->val && root->val>q->val) {//往左去
                TreeNode* l=lowestCommonAncestor(root->left,p,q);
                return l;
            }
            else if (root->val<p->val && root->val<q->val) {//往左去
                TreeNode* r=lowestCommonAncestor(root->right,p,q);
                return r;
            }
            //如果在区间中间，遇到的第一个节点就是最近公共祖先
            else return root;
        }
    };