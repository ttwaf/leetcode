/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);//dp[j]表j为n的完全平方数的数量

        dp[0]=0;//虽然不会遍历到0，但是会用到dp[0]

        for (int i=1;i<=100;i++) {//n的范围是100的平方
            for (int j=i*i;j<=n;j++) {
                if (dp[j-i*i]==INT_MAX) continue;//如果还是最值，说明不会更优了。跳过
                dp[j]=min(dp[j],dp[j-i*i]+1);//腾出空间用上这个数，就加一种方法。
            }
        }
        return dp[n];
    }
};
// @lc code=end

