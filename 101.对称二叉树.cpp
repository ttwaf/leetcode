/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {//迭代写法用stack
//         stack<TreeNode*> st;
//         if (!root) return true;
//         st.push(root->left);
//         st.push(root->right);
//         while (!st.empty()) {
//             TreeNode* l=st.top(); st.pop();
//             TreeNode* r=st.top(); st.pop();
//             if (l==nullptr&&r==nullptr) continue;
//             if (l==nullptr || r==nullptr || l->val!=r->val) return false;
//             st.push(l->left);
//             st.push(r->right);
//             st.push(l->right);
//             st.push(r->left);
//         }
//         return true;
//     }
// };
class Solution {//递归写法
    public:
    
        //不是单纯遍历，而是开了个头之后去比较。这个头一定要写的，才好让它自己去递归
        bool cmp (TreeNode* l,TreeNode* r) {
            //1入口2出口3逻辑
            if (l==NULL&&r==NULL) return true;
            if (l==NULL || r==NULL || l->val!=r->val) return false;
    
            bool out=cmp(l->left,r->right);
            bool in=cmp(l->right,r->left);
            return out&&in;
        }
    
        bool isSymmetric(TreeNode* root) {//迭代写法
            if (!root) return true;
            return cmp(root->left,root->right);
        }
    };
// @lc code=end
// class Solution {
//     public:
//         bool isSymmetric(TreeNode* root) {//迭代写法
    
//             queue<TreeNode*> que;
//             if (root==NULL) return true;
//             que.push(root->left);
//             que.push(root->right);
//             while (!que.empty()) {
//                 TreeNode* l=que.front(); que.pop();
//                 TreeNode* r=que.front(); que.pop();
//                 if (l==NULL&&r==NULL) continue;//先排除第一种情况，那剩下的就是左右只有一个为空，或者都不为空的情况
//                 if (l==NULL || r==NULL || l->val!=r->val) return false;
//                 que.push(l->left);//为空也可以入队
//                 que.push(r->right);
//                 que.push(l->right);
//                 que.push(r->left);
//             }
//             return true;
//         }
//     };

// class Solution {//递归写法
//     public:
    
//         //不是单纯遍历，而是开了个头之后去比较。这个头一定要写的，才好让它自己去递归
//         bool cmp (TreeNode* l,TreeNode* r) {
//             //1入口2出口3逻辑
//             if (l==NULL&&r==NULL) return true;
//             if (l==NULL || r==NULL || l->val!=r->val) return false;
    
//             bool out=cmp(l->left,r->right);
//             bool in=cmp(l->right,r->left);
//             return out&&in;
//         }
    
//         bool isSymmetric(TreeNode* root) {//迭代写法
//             if (!root) return true;
//             return cmp(root->left,root->right);
//         }
//     };