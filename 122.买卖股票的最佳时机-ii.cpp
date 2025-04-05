/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {//滚动数组版
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2,vector<int>(2));
        //第i天有两个状态。0表示不持有股票。1表示持有股票

        if (n==1) return 0;
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        //i%2随着i++是交替的。只有2*2的数组大小。第一列的前一天可能是第二列
        for (int i=1;i<n;i++) {
            //不持有：继续不持有或者卖出了
            dp[i%2][0]=max(dp[(i-1)%2][0],dp[(i-1)%2][1]+prices[i]);
            //卖了更赚就卖，不然就一直留着
            //持有：继续持有或者没有时再买入
            dp[i%2][1]=max(dp[(i-1)%2][1],dp[(i-1)%2][0]-prices[i]);
            //亏的少再持有股票，不然就不持有。
        }

        return dp[(n-1)%2][0];//最后一天保持和for循环的最后一次相一致
    }
};
// @lc code=end

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>> dp(n+1,vector<int>(2));
            //第i天有两个状态。0表示不持有股票。1表示持有股票
    
            if (n==1) return 0;
            dp[0][0]=0;
            dp[0][1]=-prices[0];
    
            for (int i=1;i<n;i++) {
                //不持有：继续不持有或者卖出了
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                //卖了更赚就卖，不然就一直留着
                //持有：继续持有或者没有时再买入
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
                //亏的少再持有股票，不然就不持有。
            }
    
            return dp[n-1][0];//不持有一定比持有大
        }
    };