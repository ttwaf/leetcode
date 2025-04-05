/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
class Solution {//递归基础版
public:
    TreeNode* searchBST(TreeNode* root, int val) {//迭代版
        //因为本就有序，查起来很方便
        while (root) {
            if (root->val==val) break;//加在最前最后均可。力扣加在最后，我加在最前
            if (root->val>val) root=root->left;
            else if (root->val<val) root=root->right;
        }
        return root;
    }
};
// @lc code=end

class Solution {//递归精简版
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
    
            if (root->val==val || root==nullptr) return root;
            if (root->val>val) return searchBST(root->left,val);
            if (root->val<val) return searchBST(root->right,val);
            // return nullptr;//应该只是为了通过编译。不然leetcode不给过
        }
    };

class Solution {//递归基础版
    public:
        TreeNode* searchBST(TreeNode* root, int val) {
    
            if (root==nullptr || root->val==val) return root;
            //设一个来接住返回值
            TreeNode* res = new TreeNode();
            //左
            if (root->val > val) {
                res=searchBST(root->left,val);
            }
            //右
            if (root->val < val) {
                res=searchBST(root->right,val);
            }
            return res;
        }
    };