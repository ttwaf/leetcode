/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int sum;
    void trace(vector<int>& candidates, int target,int idx,int sum) {

        if (sum==target) {
            res.push_back(path);
            return ;
        }
        //在for循环里剪枝记得在主函数里排序
        for (int i=idx;i<candidates.size() && sum+candidates[i]<=target;i++) {
            if (i>idx && candidates[i]==candidates[i-1]) continue;//去重
            sum+=candidates[i];
            path.push_back(candidates[i]);
            trace(candidates,target,i+1,sum);//每个数字只能使用一次
            sum-=candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        trace(candidates,target,0,sum);
        return res;
    }
};
// @lc code=end

