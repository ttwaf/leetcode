/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int sum=0;
    void trace(int k,int n,int sum,int s) {
        if (sum>n) return ;//剪枝。如果超过了，后面就没必要了
        if (path.size()==k) {//数量足无论是否达标都需要返回。k是树的深度
            if (n==sum) res.push_back(path);//要写两层判断。
            return ;
        }

        for (int i=s;i<=9-(k-path.size())+1;i++) {//所有数-已有的数+1。数量不足了就不用了
            sum+=i;
            path.push_back(i);
            trace(k,n,sum,i+1);
            sum-=i;
            path.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        trace(k,n,sum,1);//传入中间结果和起点
        return res;
    }
};
// @lc code=end

