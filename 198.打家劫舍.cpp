/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //感觉是线性dp
        int n=nums.size();
        int m=INT_MIN;

        vector<int> dp(n+1,0);//物品是房间i。重量是金额。求最大值
        //dp表从左往右偷能偷到的最大金额。
        // for (int i=0;i<n;i++) dp[i]=nums[i];
        if (n==0) return 0;
        if (n==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for (int i=2;i<n;i++) {//一家一家偷。偷到第i家为止
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
// @lc code=end

