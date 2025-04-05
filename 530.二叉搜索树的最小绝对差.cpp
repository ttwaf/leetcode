/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    

    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        if (root==nullptr) return 0;
        st.push(root);
        TreeNode* cur=root;
        TreeNode* pre=nullptr;
        int m=__INT_MAX__;
        while (!st.empty()) {//中序遍历
            if (cur!=nullptr) {//压入栈
                st.push(cur);
                cur=cur->left;//左
            } else {
                //中
                cur=st.top();
                st.pop();
                if (pre!=nullptr) m=min(m,cur->val-pre->val);
                pre=cur;
                cur=cur->right;//右
            }
        }
        return m;
    }
};
// @lc code=end

class Solution {//递归版
    public:
        int m=INT_MAX;
        TreeNode* pre=nullptr;
        void traversal(TreeNode* root) {
            if (root==nullptr) return;
            traversal(root->left);//左
            if (pre!=nullptr) m=min(m,root->val-pre->val);
            pre=root;
            traversal(root->right);//右
            return ;
        }
    
        int getMinimumDifference(TreeNode* root) {
            
            traversal(root);
            return m;
        }
    };

class Solution {//转为数组
    public:
    
        //转为有序数组
        vector<int> vec;
        void traversal(TreeNode* root) {
            if (root==nullptr) return ;
            traversal(root->left);//先到左
            vec.push_back(root->val);//中
            traversal(root->right);//右
            return ;
        }
    
        int getMinimumDifference(TreeNode* root) {
            vector<int> res;
            traversal(root);
            int m=INT_MAX;
            for (int i=1;i<vec.size();i++) {
                m=min(vec[i]-vec[i-1],m);
            }
            return m;
        }
    };