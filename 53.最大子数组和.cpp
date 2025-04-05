/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);//以i结尾的最大连续子数组和

        //依据就是表格。
        //再头脑中模拟一遍。
        dp[0]=nums[0];
        int res=dp[0];
        for (int i=1;i<n;i++) {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);//舍弃掉一些状态。每一层遍历都只留下最好的状态。
            res=max(res,dp[i]);
        }
        return res;
    }
};
// @lc code=end

