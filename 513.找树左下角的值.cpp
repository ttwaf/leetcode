/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
        int findBottomLeftValue(TreeNode* root) {//迭代
            queue<TreeNode*> que;
            if (root) que.push(root);
            int v;
            while (!que.empty()) {
                int sz=que.size();
                for (int i=0;i<sz;i++) {
                    //中取出即可，没有处理
                    TreeNode* cur=que.front();
                    que.pop();
                    //法二：一直更新第一个即可。最后会留下最后一行第一个。
                    if (i==0) v=cur->val;
                    //左
                    if (cur->left) que.push(cur->left); 
                    //右
                    if (cur->right) que.push(cur->right);
                }
            }
            return v;
        }
    };
// @lc code=end

class Solution {//递归
    public:
        int md=INT_MIN;
        int res;
        void traversal(TreeNode* cur, int depth) {
            //终止条件是叶结点而非空节点
            if (cur->left==nullptr && cur->right==nullptr) {
                if (depth>md) {//维护
                    md=depth;
                    res=cur->val;
                    return ;
                }
            }
            //中。不需要逻辑处理
            //左
            if (cur->left) traversal(cur->left,depth+1);
            //右
            if (cur->right) traversal(cur->right,depth+1);
            return ;
        }

        int findBottomLeftValue(TreeNode* root) {
            int depth=0;
            traversal(root,depth);
            return res;
        }
    };

class Solution {
    public:
        int findBottomLeftValue(TreeNode* root) {//自己的迭代
            queue<TreeNode*> que;
            if (root) que.push(root);
            int v;
            while (!que.empty()) {
                //中取出即可，没有处理
                TreeNode* cur=que.front();
                que.pop();
                //处理.
                //法一：找第一个叶结点.中右左的层序去遍历，最后一个节点就是最后一层的最左节点
                if (cur->left==nullptr && cur->right==nullptr) {
                    v=cur->val;
                }
                //右
                if (cur->right) que.push(cur->right);
                //左
                if (cur->left) que.push(cur->left); 
            }
            return v;
        }
    };