/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
class Solution {//二叉搜索迭代版
public:

    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur=root;
        TreeNode* pre=nullptr;
        int cnt=0,mcnt=0;
        vector<int> res;

        while (cur!=nullptr || !st.empty()) {
            if (cur!=nullptr) {
                //左
                st.push(cur);//放进去
                cur=cur->left;
            } else {//到底了
                cur=st.top();//拿出中
                st.pop();
                //中
                //维护计数器
                if (pre==nullptr || pre->val!=cur->val) cnt=1;
                else cnt++;
                //更新pre指针
                pre=cur;

                //维护最大值与结果集
                if (mcnt==cnt) res.push_back(cur->val);
                if (cnt>mcnt) {
                    mcnt=cnt;
                    res.clear();
                    res.push_back(cur->val);
                }
                //右
                cur=cur->right;
            }
        } 
        return res;
    }
};
// @lc code=end

class Solution {//二叉搜索递归版
    public:
    
        int cnt=0;
        int mcnt=0;
        vector<int> res;
        TreeNode* pre=nullptr;
    
        void search(TreeNode* cur) {
            if (cur==nullptr) return;
            //左
            search(cur->left);
            //中
            if (pre==nullptr||pre->val!=cur->val) cnt=1;//是第一个节点，或者与前一个节点值不同
            else cnt++;//与前一个节点值相同
            pre=cur;//更新前一个节点
    
            //维护结果集
            if (cnt==mcnt) res.push_back(cur->val);
    
            if (cnt>mcnt) {//更新结果集
                mcnt=cnt;
                res.clear();//清空后更新
                res.push_back(cur->val);
            }
            
            //右
            search(cur->right);
            return ;
        }
    
        vector<int> findMode(TreeNode* root) {
            search(root);
            return res;        
        }
    };

class Solution {//普通二叉递归版
    public:
    
        void traversal(TreeNode* root,unordered_map<int,int>& m) {
            if (root==nullptr) return ;
            m[root->val]++;
            traversal(root->left,m);
            traversal(root->right,m);
            return ;
        }
    
        bool static cmp(const pair<int,int> a,const pair<int,int> b) {
            return a.second>b.second;
        }
    
        vector<int> findMode(TreeNode* root) {
            //遍历之后按出现次数（map的值）排好序
            unordered_map<int,int> m;
            traversal(root,m);//没在全局定义，就从参数传进去
            vector< pair<int,int> > vec( m.begin(), m.end() );
            sort(vec.begin(),vec.end(),cmp);
            //造出返回值
            vector<int> res;
            res.push_back(vec[0].first);
            for (int i=1;i<vec.size();i++) {
                if (vec[i].second==vec[0].second) res.push_back(vec[i].first);
                else break;
            }
            return res;
        }
    };