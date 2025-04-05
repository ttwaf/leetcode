/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5));
        //奇数表示持有股票。偶数表示不持有股票

        dp[0][0]=0;
        dp[0][1]=-prices[0];//第一天买入了
        dp[0][2]=0;//第一天买第一天卖。为0
        dp[0][3]=-prices[0];//第一天买入卖出后，第二次买入
        dp[0][4]=0;//第一天第二次卖出
        
        //不能同时参与多笔交易，保证了dp是线性的
        for (int i=1;i<n;i++) {
            //第一次持有股票
            dp[i][1]=max(dp[i-1][1],-prices[i]);//是第一次买入，所以之前一定是0
            //第一次卖出股票
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]+prices[i]);
            //第二次持有股票.再第一次卖出之后再买入
            dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i]);
            //第二次不持有股票，在第二次买入之后再卖出
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }
        return dp[n-1][4];
    }
};
// @lc code=end

