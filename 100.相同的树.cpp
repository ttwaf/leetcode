/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
        if (l==nullptr || r==nullptr || l->val!=r->val) {
            return false;
        }
//再由左到右，由上到下比较下一队。入队顺序和递归的参数传入顺序一样。
//下面三句和return语句是等价的。只是这样拆开来更容易看得清楚。不然混在一起没了次序难分清
        // bool isl=cmp(l->left,r->left);
        // bool isr=cmp(l->right,r->right);
        // return isl&&isr;

        return cmp(l->left,r->left)&&cmp(l->right,r->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {//递归版
        return cmp(p,q);//理解：主函数从0起始，递归函数从1开始
    }
};
// @lc code=end

// bool isSameTree(TreeNode* p, TreeNode* q) {//迭代版

//     queue<TreeNode*> que;
//     que.push(p);
//     que.push(q);
//     while (!que.empty()) {
//         int sz=que.size();
//         // for (int i=0;i<sz;i++) {

//         TreeNode* l=que.front(); que.pop();
//         TreeNode* r=que.front(); que.pop();
//         if (l==NULL&&r==NULL) continue;
//         if (l==NULL || r==NULL || l->val!=r->val) return false;                
//         que.push(l->left);
//         que.push(r->left);
//         que.push(l->right);
//         que.push(r->right);
//         // }
//     }
//     return true;
// }