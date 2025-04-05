/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
class Solution {//索引版
public:
    //中序：[inbegin,inend)。后序：[postbegin,postend)
    TreeNode* traversal(vector<int>& inorder,int inbegin, int inend,vector<int>& postorder,int postbegin,int postend) {
        //左闭右开，相等时意味着空了。
        if (postbegin==postend) return nullptr;
        //中
        //从后序取出根节点
        // int val=postorder[postorder.size()-1];//太长了。分开写比较好
        int val=postorder[postend-1];
        TreeNode* root = new TreeNode(val);

        //用根节点找中序切割点
        int idx=0;
        for (idx=inbegin;idx<inend;idx++) {
            if (root->val==inorder[idx]) break;
        }
        //切割中序。不用定义vector，而是直接拿参数去做。前三个从begin来，最后一个从end来
        //[inbegin,idx),idx,[idx+1,inend)
        int lftinbegin=inbegin;
        int lftinend=idx;//右开
        int riginbegin=idx+1;
        int riginend=inend;
        //切割后序
        //[postbegin,postbegin+len),[postbegin+len,postend-1)前三个从begin来，最后一个从end来
        int lftpostbegin=postbegin;
        int lftpostend=postbegin+(lftinend-lftinbegin);
        int rigpostbegin=postbegin+(lftinend-lftinbegin);
        int rigpostend=postend-1;

        //学一下调试
        // cout<<"--------------------"<<endl;
        // for (int i=lftinbegin;i<lftinend;i++) cout<<inorder[i]<<" ";
        // cout<<endl;
        // for (int i=riginbegin;i<riginend;i++) cout<<inorder[i]<<" ";
        // cout<<endl;
        // for (int i=lftpostbegin;i<lftpostend;i++) cout<<postorder[i]<<" ";
        // cout<<endl;
        // for (int i=rigpostbegin;i<rigpostend;i++) cout<<postorder[i]<<" ";
        // cout<<endl;
        // cout<<lftinbegin<<" "<<lftinend<<endl;
        // cout<<lftpostbegin<<" "<<lftpostend<<endl;
        // cout<<riginbegin<<" "<<riginend<<endl;
        // cout<<rigpostbegin<<" "<<rigpostend<<endl;

        //左.都是left
        root->left = traversal(inorder, lftinbegin,lftinend, postorder, lftpostbegin,lftpostend);
        //右。都是right
        root->right = traversal(inorder, riginbegin,riginend, postorder, rigpostbegin,rigpostend);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};
// @lc code=end




class Solution {//vector版
    public:
    
        TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
            //终止条件.以后序的顺序为主。因为两个序列代表的是同一棵树
            if (postorder.size()==0) return nullptr;
    
            //找到后序的最后一个节点当根节点
            TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
            //找中序的切割点
            int idx=0;
            for (idx=0;idx<inorder.size();idx++) {
                if (inorder[idx]==root->val) break;
            }
    
            //根据切割点切割中序数组（左闭右开）。用中序本身去构造中序左右
            //[0,idx)，即[0,idx-1]
            vector<int> inleft(inorder.begin(),inorder.begin()+idx);
            //[idx+1,inorder.size)，即[idx+1,inorder.size-1]
            vector<int> inright(inorder.begin()+idx+1,inorder.end());
            //可见[0,idx-1]，[idx+1,inorder.size-1]跳过了root那一个
            postorder.resize(postorder.size()-1);
    
            //切割后序数组。用后序本身配合中序左右大小去构造后序左右
            //[0,inleft.size)，即[0,inleft.size-1]
            vector<int> postleft(postorder.begin(),postorder.begin()+inleft.size());
            //[inleft.size,postorder.size)，即[inleft.size,postorder.size-1)
            vector<int> postright(postorder.begin()+inleft.size(), postorder.end());
    
            // // 以下为日志
            // cout << "----------" << endl;
    
            // cout << "leftInorder :";
            // for (int i : inleft) {
            //     cout << i << " ";
            // }
            // cout << endl;
    
            // cout << "rightInorder :";
            // for (int i : inright) {
            //     cout << i << " ";
            // }
            // cout << endl;
    
            // cout << "leftPostorder :";
            // for (int i : postleft) {
            //     cout << i << " ";
            // }
            // cout << endl;
            //  cout << "rightPostorder :";
            // for (int i : postright) {
            //     cout << i << " ";
            // }
            // cout << endl;
            //注意传入的是相同的集合！！
            root->left=traversal(inleft,postleft);
            root->right=traversal(inright,postright);
            return root;
        }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            
            return traversal(inorder, postorder);
        }
    };