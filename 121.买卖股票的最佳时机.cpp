/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        //第i天有两个状态。dp[i][0]表示不持有股票，dp[i][1]表示持有股票

        if (n==1) return 0;
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for (int i=1;i<n;i++) {//天天相扣，递推
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//没有股票，不动，或者卖出了
            //保证了不会在亏钱的时候卖出。更赚钱就用之前没卖的状态去加
            dp[i][1]=max(dp[i-1][1],-prices[i]);//有股票，不动，或者买了(全程只能买卖一次。所以一定是-prices[i])
            //保证没有更低的入手时机。有更好的入手时机就入手
        }
        return dp[n-1][0];//一定是不持有股票，股票换了钱一定更大。
    }
};
// @lc code=end

