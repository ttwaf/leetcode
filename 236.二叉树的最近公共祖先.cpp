/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
class Solution {//递归精简版
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //终止条件:为p或为q，说明找到了p或q，为空，说明没找到，没区别
        if (root==p || root==q || root==nullptr) return root;
        //左
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        //右
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        //中。找到了左右的话
        if (l!=nullptr && r!=nullptr) return root;//左右都不空，说明它就是
        if (l==nullptr) return r;//一句话包含两种情况：r有值，则返回r。r为空，则返回空
        else return l;//l不为空是同样的情况
    }
};
// @lc code=end

class Solution {//递归精简版
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            //终止条件:为p或为q，说明找到了p或q，为空，说明没找到，没区别
            if (root==p || root==q || root==nullptr) return root;
            //左
            TreeNode* l=lowestCommonAncestor(root->left,p,q);
            //右
            TreeNode* r=lowestCommonAncestor(root->right,p,q);
            //中。找到了左右的话
            if (l!=nullptr && r!=nullptr) return root;//左右都不空，说明它就是
            if (l==nullptr) return r;//一句话包含两种情况：r有值，则返回r。r为空，则返回空
            else return l;//l不为空是同样的情况
        }
    };

class Solution {//递归基础版
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            //终止条件:为p或为q，说明找到了p或q，为空，说明没找到，没区别
            if (root==p || root==q || root==nullptr) return root;
            //左
            TreeNode* l=lowestCommonAncestor(root->left,p,q);
            //右
            TreeNode* r=lowestCommonAncestor(root->right,p,q);
            //中。找到了左右的话
            if (l!=nullptr && r!=nullptr) return root;//左右都不空，说明它就是
            if (l==nullptr && r!=nullptr) return r;//如果左为空右不为空，说明在右
            else if (l!=nullptr && r==nullptr) return l;//左不空右空，说明在左
            else return nullptr;//都为空，说明没有
        }
    };