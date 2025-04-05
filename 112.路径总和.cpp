/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
        bool hasPathSum(TreeNode* root, int targetSum) {//迭代不方便回溯，没写完
            stack< pair<TreeNode*,int> > st;
            if (root) st.push( pair<TreeNode*,int>(root,root->val) );
            while (!st.empty()) {//写中右左实现中左右
                //中
                pair<TreeNode*,int> cur=st.top();
                st.pop();
                //是叶子的话
                if (cur.first->left==nullptr && cur.first->right==nullptr && targetSum==cur.second) {
                    return true;
                } 
                //右
                if (cur.first->right) {
                    st.push( pair<TreeNode*,int>(cur.first->right,cur.second+cur.first->right->val) );
                }
                //左
                if (cur.first->left) {
                    st.push( pair<TreeNode*,int>(cur.first->left,cur.second+cur.first->left->val) );
                }
            }
            return false;
        }
    };
// @lc code=end



    class Solution {//递归版
        public:
            bool flg;
            bool traversal(TreeNode* cur, int sum, int targetSum) {
                if (cur->left==nullptr && cur->right==nullptr) {
                    if (sum==targetSum) return true;
                }
                bool l,r;//默认为false
                //左有无
                if (cur->left) l=traversal(cur->left, sum+cur->left->val, targetSum);
                //右有无
                if (cur->right) r=traversal(cur->right, sum+cur->right->val, targetSum);
                //中。
                return l|r;
            }
        
            bool hasPathSum(TreeNode* root, int targetSum) {//迭代不方便回溯
                int sum=0;//回溯变量
                if (root==nullptr) return false;
                return traversal(root,sum+root->val,targetSum);
            }
        };