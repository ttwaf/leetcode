/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1));

        for (int j=1;j<=2*k;j++) {
            if (j%2)
                dp[0][j]=-prices[0];//奇数是买入了。偶数是又卖出了相当于没操作
        }

        for (int i=1;i<n;i++) {
            for (int j=1;j<=2*k;j++) {
                // if (j==1) {//第一次一定是这样.初始化只保证了第0天。所以这样
                //     dp[i][j]=max(dp[i-1][j],-prices[i]);//保证一定是第一次买入
                // }//这是只买卖一次。买卖多次的话不用加这个
                if (j%2==1) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);//奇数买入，减去
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+prices[i]);//偶数卖出，加上
                
            }
        }
        //1是第一次买入，2是第一次卖出，3是第二次买入，4是第二次卖出...
        //类推得到奇数是买入，偶数是卖出。
        return dp[n-1][2*k];
    }
};
// @lc code=end

