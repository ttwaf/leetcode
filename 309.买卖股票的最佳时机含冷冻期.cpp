/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5));
        //1表持有股票(可以卖了)，2表不持有股票（刚卖不能买，进入了冷冻期）
        //0表不持有股票（可以买，过了冷冻期）

        dp[0][1]=-prices[0];
        

        for (int i=1;i<n;i++) {
            //不持有股票:继续不持有，前一天卖了（只能在非冷冻期卖）
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]);
            //持有股票(前一天不是冷冻期):继续持有，昨天(不是冷冻期)买的
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]);
            //不持有股票（昨天卖了），只有一种可能，卖了之后进入了冷冻期
            dp[i][2]=dp[i-1][1]+prices[i];
        }

        
        return max(dp[n-1][0],dp[n-1][2]);//不持有
    }
};
// @lc code=end

