/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool cmp(TreeNode* l,TreeNode* r) {

        if (l==nullptr&&r==nullptr) return true;
        if (l==nullptr||r==nullptr||l->val!=r->val) return false;
        
        // bool isl=cmp(l->left,r->left);
        // bool isr=cmp(l->right,r->right);
        // return isl&&isr;

        return cmp(l->left,r->left)&&cmp(l->right,r->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr) return true;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {//这是用队列深搜了属于是。先序遍历
            TreeNode* cur=que.front(); 
            que.pop();
            if (cmp(cur,subRoot)) return true;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        return false;

    }
};
// @lc code=end

// class Solution {
//     public:
//         bool cmp(TreeNode* l, TreeNode* r) {
//             if (l==nullptr&&r==nullptr) return true;
//             if (l==nullptr||r==nullptr||l->val!=r->val) return false;
    
//             // bool isl=cmp(l->left,r->left);
//             // bool isr=cmp(l->right,r->right);
//             // return isl&&isr;
//             return cmp(l->left,r->left) && cmp(l->right,r->right);
//         }
    
//         bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//             if (!root) return false;
//             return cmp(root,subRoot) || 
//             isSubtree(root->left,subRoot) || 
//             isSubtree(root->right,subRoot);
//         }//和100相同的树的唯一区别就是这里的return多了后面两个条件
//     };