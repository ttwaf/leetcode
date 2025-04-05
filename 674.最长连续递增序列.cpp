/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int res=1;
        vector<int> dp(n+1,1);//长度至少为1.初始化为1
        for (int i=1;i<n;i++) {
            if (nums[i]>nums[i-1]) dp[i]=max(dp[i],dp[i-1]+1);
            res=max(res,dp[i]);//留下每轮最长的，以供返回
        }
        return res;
    }
};
// @lc code=end

