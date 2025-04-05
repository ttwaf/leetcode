/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int res;//全局定义，才能用
    void getDepth(TreeNode* root,int depth) {//递归版先序遍历（中左右）
        //
        if (root==NULL) return;

        //中：是叶子节点
        if (!root->left && !root->right) res=min(res,depth);
        //左
        if (root->left) getDepth(root->left,depth+1);
        //右
        if (root->right) getDepth(root->right,depth+1);
        return;
    }

    int minDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        res = INT_MAX;
        getDepth(root,1);//逻辑放在参数里处理逻辑了
        return res;
    }
};
// @lc code=end

class Solution {
    public:
    
        int getDepth(TreeNode* root) {//递归后序遍历（左右中）
            if (root==NULL) return 0;
            //后面的
            int ld=getDepth(root->left);//左
            int rd=getDepth(root->right);//右
            //这一层的（中）
            if (root->left && !root->right) return 1+ld;//左有右没有
            if (!root->left && root->right) return 1+rd;//左没有右有
            //左右都没有
            int res=min(ld,rd);
            return res+1;
        }
    
        int minDepth(TreeNode* root) {//递归版
            return getDepth(root);
        }
    };

int minDepth(TreeNode* root) {//迭代版
    queue<TreeNode*> que;
    if (root) que.push(root);
    int depth=0;
    int flg=0;
    while (!que.empty()) {
        int sz=que.size();
        depth++;
        for (int i=0;i<sz;i++) {
            TreeNode* cur=que.front();
            que.pop();
            if (cur->left==NULL && cur->right==NULL) {
                return depth;
            }
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            
        }
    }
    return depth;
}
