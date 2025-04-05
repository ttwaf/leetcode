/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution {//迭代版
public:

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        if (root==nullptr) return true;
        TreeNode* cur=root;
        TreeNode* pre=nullptr;
        while (cur!=nullptr || !st.empty()) {
            if (cur!=nullptr) {//统一全部压入栈，从最左下角开始
                st.push(cur);
                //左
                cur=cur->left;
            } else {
                //中
                cur=st.top();
                st.pop();
                if (pre!=nullptr && pre->val>=cur->val) return false;
                pre=cur;//验证完就更新 
                //右
                cur=cur->right;
            }
        }
        return true;
    }
};
// @lc code=end

class Solution {//递归前一个节点版
    public:
        //递归每层都会做。所以选择全局记录。取前一个节点即左结点
        TreeNode* pre;
        bool isValidBST(TreeNode* root) {
            if (root==nullptr) return true;
            //左
            bool l=isValidBST(root->left);
            //中
            if (pre!=nullptr && pre->val>=root->val) return false;
            pre = root;//让它无论如何都能更新前一个节点。因为它是没有条件的，不需要条件的
            //右
            bool r=isValidBST(root->right);
            return l&&r;
        }
    };

class Solution {//条件错误版
    public:
        //递归每层都会做。所以选择全局记录
        TreeNode* pre;
        bool isValidBST(TreeNode* root) {
            if (root==nullptr) return true;
            //左
            bool l=isValidBST(root->left);
            //中
            if (pre!=nullptr && pre->val<root->val) pre=root;
            else return false;//这么写的话pre为空时也会判false，一开始就为空，所以结果全是false
            //右
            bool r=isValidBST(root->right);
            return l&&r;
        }
    };

class Solution {//初始化最小值版
    public:
        // int m=INT_MIN;//样例里有2147483647
        long long m=LONG_MIN;
        bool isValidBST(TreeNode* root) {
    
            if (root==nullptr) return true;
    
            //左
            bool l=isValidBST(root->left);
            //中.验证它是个递增的序列。即中必须大于左，右必须大于中
            if (root->val>m) m=root->val;
            else return false;
            //右
            bool r=isValidBST(root->right);
            return l && r;
        }
    };

class Solution {//一开始写错的
    public:
        bool isValidBST(TreeNode* root) {
            // if (root==nullptr) return true;
            if (!root->left && !root->right) return true;
            //左
            if (root->left) {
                if (root->left->val < root->val) return isValidBST(root->left);
                else return false;
            } 
            //右
            if (root->right) {
                if (root->right->val > root->val) return isValidBST(root->right);
                else return false;
            } 
            return false;
        }
    };