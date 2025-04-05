/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

    vector<string> binaryTreePaths(TreeNode* root) {//迭代版

        stack<string> pathst;
        vector<string> res;
        stack<TreeNode*> st;//这里要迭代遍历，而不是层序遍历，故用stack
        //统一排除，就不用在每个栈前面判断
        if (root==nullptr) return res; 
        st.push(root);//节点的栈
        pathst.push(to_string(root->val));//节点对应的栈
        while (!st.empty()) {
            
            //中。把要用的路径弹出来
            TreeNode* cur=st.top(); st.pop();
            string path=pathst.top(); pathst.pop();//
            if (cur->left==nullptr && cur->right==nullptr) {//叶子节点
                res.push_back(path);
            }
            //后面两步把路径加完塞回去
            //右
            if (cur->right) {
                st.push(cur->right);
                pathst.push(path+"->"+to_string(cur->right->val));
            } 
            //左
            if (cur->left) {
                st.push(cur->left);
                pathst.push(path+"->"+to_string(cur->left->val));
            }
        }
        return res;
    }
};
// @lc code=end

class Solution {
    public:
        //精简递归。以这个为主
        //注意这里的path只是单纯复制，不是引用
        void traversal(TreeNode* root, string path, vector<string>& res) {
            //中
            path+=to_string(root->val);
            if (root->left==nullptr && root->right==nullptr) {//是叶子结点
                res.push_back(path);
                return ;
            }
            //不用回退了.因为是单纯复制用值。函数退出来之后没有变化。隐含了回溯
            //左
            if (root->left) traversal(root->left,path+"->",res);
            //右
            if (root->right) traversal(root->right,path+"->",res);
            return ;
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            //参数准备好，直接进入递归
            string path;
            vector<string> res;
            if (!root) return res;
            traversal(root,path,res);
            return res;
        }
    };

class Solution {
    public:
        //复杂版递归。不用这版
        void traversal(TreeNode* root, vector<int>& path, vector<string>& res) {
            //1入口2出口3单层逻辑
            //中，也是出口
            path.push_back(root->val);
            if (root->left==nullptr && root->right==nullptr) {//是叶子节点
    
                string s;//设一个临时的存path字符型的变量
                int sz=path.size();
                for (int i=0;i<sz-1;i++) {//将int的path转为string
                    s += to_string(path[i]);
                    s += "->";
                }
                s += to_string(path[sz-1]);//为了少走一个'->'，同时存入当前节点
                res.push_back(s);
                return;//回溯，回退会上层
            }
            //左
            if (root->left) {
                traversal(root->left,path,res);
                path.pop_back();//回溯，就是回退一格，去走别的路
            }
            //右
            if (root->right) {
                traversal(root->right,path,res);
                path.pop_back();//回溯
            }
            return;//走完了，就返回上层。最后返回主函数。这一句可以省略掉
        }
    
        vector<string> binaryTreePaths(TreeNode* root) {
            //参数准备好，直接进入递归
            vector<int> path;//暂存单层递归的结果
            vector<string> res;//存每层递归的返回结果.存的是一条条路径string
            if (!root) return res;
            traversal(root,path,res);
            return res;
        }
    };

