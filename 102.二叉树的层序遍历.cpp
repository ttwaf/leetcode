/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
        void order(TreeNode* cur,vector<vector<int>>& res,int depth) {
            //1、入口 2、出口 3、单层递归逻辑
            if (!cur) return;//空指针返回
            if (res.size()==depth)  res.push_back(vector<int>());//创建一个新的空的数组进去
            res[depth].push_back(cur->val);//对应深度对应插入，对号入座
            order(cur->left,res,depth+1);
            order(cur->right,res,depth+1);
        }

        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            int depth=0;//从0开始生成。每到新的一层就创建一个新的数组。第一层进去也在第一层才开始生成，保证后面再次回到这层时不会重复创建
            order(root,res,depth);//开头和结果每一层都要用到，每层会加1也要用
            return res;
        }
    };
// @lc code=end
// class Solution {//迭代版
//     public:
//         vector<vector<int>> levelOrder(TreeNode* root) {
//             queue<TreeNode*> que;
//             vector<vector<int>> res;
//             if (root) que.push(root);
//             while (!que.empty()) {
//                 int sz=que.size();
//                 vector<int> vec;
//                 for (int i=0;i<sz;i++) {
//                     TreeNode* cur=que.front();
//                     que.pop();
//                     vec.push_back(cur->val);
//                     if (cur->left) que.push(cur->left);
//                     if (cur->right) que.push(cur->right);
//                 }
//                 res.push_back(vec);//因为返回形式是vector<vector<int>>。要熟悉这种写法
//             }
//             return res;
//         }
//     };
