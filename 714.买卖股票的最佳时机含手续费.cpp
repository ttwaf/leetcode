/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //0表不持有股票，1表持有股票
        //第一天持有股票的时候把手续费交了(统一再买入时交钱)
        dp[0][1]=-prices[0]-fee;

        for (int i=1;i<n;i++) {
            //不持有股票：卖了股票赚钱
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            //持有股票；买股票的时候把手续费交了
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];
    }
};
// @lc code=end

