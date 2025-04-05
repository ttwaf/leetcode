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
        TreeNode* traversal(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd) {
            //左闭右开相等
            if (preEnd-preBegin==0) return nullptr;
            //中
            //取出前序的节点为根节点
            int val=preorder[preBegin];
            TreeNode* root= new TreeNode(val);
            //以根节点找中序的分割点
            int idx=0;
            for (idx=inBegin;idx<inEnd;idx++) {//左闭右开，就是最基本的for循环的逻辑
                if (inorder[idx]==val) break;
            }
            //用分割点分割中序
            //[inBegin,idx),idx,[idx+1,inEnd)
            int lftinBegin=inBegin;
            int lftinEnd=idx;
            int riginBegin=idx+1;
            int riginEnd=inEnd;
            //用分割后的中序分割前序
            //[1+preBegin,preBegin+lftinEnd-lftinBegin),[preBegin+lftinEnd-lftinBegin,preEnd)
            int lftpreBegin=1+preBegin;
            int lftpreEnd=1+preBegin+lftinEnd-lftinBegin;
            int rigpreBegin=1+preBegin+lftinEnd-lftinBegin;
            int rigpreEnd=preEnd;
    
            // cout<<"--------------------"<<endl;
            // cout<<lftpreBegin<<" "<<lftpreEnd<<endl;
            // cout<<rigpreBegin<<" "<<rigpreEnd<<endl;
            // cout<<lftinBegin<<" "<<lftinEnd<<endl;
            // cout<<riginBegin<<" "<<riginEnd<<endl;
            // cout<<"先序左";
            // for (int i=lftpreBegin;i<lftpreEnd;i++) {
            //     cout<<preorder[i]<<" ";
            // } 
            // cout<<endl;
            // cout<<"先序右";
            // for (int i=rigpreBegin;i<rigpreEnd;i++) {
            //     cout<<preorder[i]<<" ";
            // } 
            // cout<<endl;
            // cout<<"中序左";
            // for (int i=lftinBegin;i<lftinEnd;i++) {
            //     cout<<inorder[i]<<" ";
            // } 
            // cout<<endl;
            // cout<<"中序右";
            // for (int i=riginBegin;i<riginEnd;i++) {
            //     cout<<inorder[i]<<" ";
            // } 
            // cout<<endl;
    
            //左
            root->left=traversal(preorder,lftpreBegin,lftpreEnd,inorder,lftinBegin,lftinEnd);
            //右
            root->right=traversal(preorder,rigpreBegin,rigpreEnd,inorder,riginBegin,riginEnd);
    
            return root;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return traversal(preorder,0,preorder.size(),inorder,0,inorder.size());
        }
    };