/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void trace(vector<int>& nums,int st) {//统一加&呗，这样在本体直接修改

        res.push_back(path);

        for (int i=st;i<nums.size();i++) {
            //在同一个树层中去重
            if (i>st && nums[i]==nums[i-1]) continue;//去重
            path.push_back(nums[i]);
            trace(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());//去重需要排序，避免去重不完整
        trace(nums,0);
        return res;
    }
};
// @lc code=end

