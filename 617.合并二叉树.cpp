/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==nullptr) return root2;
        if (root2==nullptr) return root1;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            //
            TreeNode* cur1=que.front(); que.pop();
            TreeNode* cur2=que.front(); que.pop();
            //中
            cur1->val+=cur2->val;
            //左右，四种情况
            if (cur1->left!=nullptr && cur2->left!=nullptr) {
                que.push(cur1->left);
                que.push(cur2->left);
            }
            if (cur1->right!=nullptr && cur2->right!=nullptr) {
                que.push(cur1->right);
                que.push(cur2->right);
            }
            if (cur1->left==nullptr && cur2->left!=nullptr) {
                cur1->left=cur2->left;
            }
            if (cur1->right==nullptr && cur2->right!=nullptr) {
                cur1->right=cur2->right;
            }
        }
        return root1;
    }
};
// @lc code=end

class Solution {//递归版
    public:
    
        TreeNode* traversal(TreeNode* root1, TreeNode* root2) {
            
            if (root1==nullptr) return root2;
            if (root2==nullptr) return root1;
    
            root1->val+=root2->val;
            root1->left=traversal(root1->left,root2->left);
            root1->right=traversal(root1->right,root2->right);
    
            return root1;
        }
    
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            root1 = traversal(root1, root2);
            return root1;
        }
    };

//失败的版本
// void traversal(TreeNode* root1, TreeNode* root2) {
//     //终止条件
//     //root1作为本树
//     //如果本树为空
//     if (root1==nullptr) {//1没有
//         //2没有就直接返回
//         if (root2==nullptr) return ;
//         else {//2有就就跳到root2
//             root1=root2;
//             return ;
//         }
//     } 
//     //如果1有，2有就加，没有就不管
//     if (root2==nullptr) return ;

//     //中
//     if (root2) root1->val+=root2->val;

//     //左
//     if (root1->left) {//1有
//         //2有
//         if (root2->left) {
//             root1->left->val+=root2->left->val;
//         } 
//         //2没有不操作.这里还忘了else。没else的话两步都会走，就不是分支了
//         traversal(root1->left,nullptr);
//     } else if (root2->left) {//1没有
//         //2有
//         root1->left=root2->left;
//         traversal(nullptr,root2->left);//改变了，但要传入原来的
//     }
//     else//12或者1有2没有。这里还忘了else。没else的话两步都会走，就不是分支了
//         traversal(root1->left,root2->left);

//     //右
//     if (root1->right) {//1有
//         //2有
//         if (root2->right) {
//             root1->right->val+=root2->right->val;
//         }
//         //2没有。这里还忘了else。没else的话两步都会走，就不是分支了
//         traversal(root1->right,nullptr);
//     } else if (root2->right) {//1没有2有
//         root1->right=root2->right;
//         traversal(nullptr,root2->right);//改变了，但要传入原来的
//     }
//     //12都有
//     traversal(root1->right,root2->right);
//     return ;
// }

// TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//     if (root1==nullptr) return root2;
//     if (root2==nullptr) return root1;
//     traversal(root1, root2);
//     return root1;
// }
//这两个版本都是自己写的失败的版本
class Solution {//这是建新树的版本
    public:
    
        TreeNode* traversal(TreeNode* root1, TreeNode* root2) {
            //中
            TreeNode* root = new TreeNode(root1->val+root2->val);
            //判出去
            if (root1->left==nullptr && root1->right==nullptr) {
                return root;
            }
            if (root2->left==nullptr && root2->right==nullptr) {
                return root;
            }
            //左
            root->left = new TreeNode();
            if (root1->left) root->left->val+=root1->left->val;
            if (root2->left) root->left->val+=root2->left->val;
            //右
            root->right = new TreeNode();
            if (root1->right) root->right->val+=root1->right->val;
            if (root2->right) root->right->val+=root2->right->val;
            return root;
        }
    
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
            if (root1==nullptr) return root2;
            if (root2==nullptr) return root1;
            return traversal(root1, root2);
        }
    };