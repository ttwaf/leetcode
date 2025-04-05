/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root) que.push(root);//预存一个
        while (!que.empty()) {//一层循环对应一层树遍历。第一层时就在把第三层塞入队列了
            vector<int> vec;
            int sz=que.size();
            for (int i=0;i<sz;i++) {//操作第三层
                TreeNode* cur=que.front();
                que.pop();
                vec.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(vec);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

