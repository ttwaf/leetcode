/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {//基础层序遍历版
        queue<TreeNode*> que;
        if (root) que.push(root);
        int cnt=0;
        while (!que.empty()) {
            int sz=que.size();
            for (int i=0;i<sz;i++) {
                TreeNode* cur=que.front();
                que.pop();
                cnt++;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return cnt;
    }
};
// @lc code=end

class Solution {
    public:
        int countNodes(TreeNode* root) {//精简递归速算版
            if (root==nullptr) return 0;
            //判断是否满二叉
            int lh=1,rh=1;//已有了一层root
            TreeNode* l=root->left;
            TreeNode* r=root->right;
            while (l) {//递归左子树
                lh++;
                l=l->left;
            }
            while (r) {//递归右子树
                rh++;
                r=r->right;
            }
            if (lh==rh) return (2<<lh-1)-1;//是满二叉则速算.左移1比直接1多了1倍。故要减1
            //不是满二叉就硬算暴力算(会局部判断是否是满二叉，加速了计算)
            return countNodes(root->left)+countNodes(root->right)+1;//左右中
        }
    };

class Solution {
    public:
        int countNodes(TreeNode* root) {//基础递归版
            // if (root==nullptr) return 0;
            // int ln=countNodes(root->left);//左
            // int rn=countNodes(root->right);//右
            // int sum=ln+rn+1;//中
            // return sum;
    
            if (root==nullptr) return 0;//精简递归版
            return countNodes(root->left)+countNodes(root->right)+1;//左右中
        }
    };