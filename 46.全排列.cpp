/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void trace(vector<int>& nums,vector<bool>& used) {
        if (path.size()==nums.size()) {
            res.push_back(path);
            return ;
        }
        for (int i=0;i<nums.size();i++) {
            if (used[i]==true) continue;
            used[i]=true;
            path.push_back(nums[i]);
            trace(nums,used);
            used[i]=false;
            path.pop_back();
        }
        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        //标记数组，位置一一对应。
        vector<bool> used(nums.size(),false);//因为要用到nums，就在这里定义，同时当递归的参数
        trace(nums,used);
        return res;
    }
};
// @lc code=end

