/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {//优化版
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(3);//到台阶i需要支付的费用
        dp[0]=0;
        dp[1]=0;
        for (int i=2;i<=n;i++) {
            int tmp=min(dp[1]+cost[i-2],dp[2]+cost[i-1]);
            dp[1]=dp[2];
            dp[2]=tmp;
        }
        return dp[2];
    }
};
// @lc code=end

class Solution {//正常版
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n=cost.size();
            vector<int> dp(n+1,0);//到台阶i需要支付的费用
            dp[0]=0;
            dp[1]=0;
            for (int i=2;i<=n;i++) {
                dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
            }
            return dp[n];
        }
    };