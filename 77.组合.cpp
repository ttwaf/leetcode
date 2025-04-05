/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {//剪枝版
public:

    vector<vector<int>> res;
    vector<int> path;

    void trace (int n,int k,int s) {

        if (k==path.size()) {//路径够长的话。k是树的深度
            res.push_back(path);
            return ;
        }
        //当成n叉树.剩的连长度都不够就剪枝
        for (int i=s;i<=n-(k-path.size())+1;i++) {//左闭右闭，n-已有的=还需要的。再+1等于开始。因为要左闭
            path.push_back(i);
            trace(n,k,i+1);//传入每一次的新起点。是回溯的优化出来的东西也是目的
            path.pop_back();//全局回溯
        }
        return ;
    }

    vector<vector<int>> combine(int n, int k) {
        trace(n,k,1);
        return res;
    }
};
// @lc code=end

class Solution {//基础版
    public:
    
        vector<vector<int>> res;
        vector<int> path;
    
        void trace (int n,int k,int s) {
    
            if (k==path.size()) {
                res.push_back(path);
                return ;
            }
    
            for (int i=s;i<=n;i++) {
                path.push_back(i);
                trace(n,k,i+1);
                path.pop_back();
            }
            return ;
        }
    
        vector<vector<int>> combine(int n, int k) {
            trace(n,k,1);
            return res;
        }
    };