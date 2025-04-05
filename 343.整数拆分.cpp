/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2]=1;//因为必须拆分为至少两个正整数。1和0拆分不了
        //从3=2+1开始拆分。n范围也从2开始
        for (int i=3;i<=n;i++) {//遍历之前的状态。从前往后遍历
            for (int j=1;j<=i/2;j++) {//从1开始拆分，保留下大的。遍历一半即可.等于号表示可以均分
                dp[i]=max(dp[i], max((i-j)*j,dp[i-j]*j));
            }//里面的max：看拆分一次，还是两次以上大。外面的max：看之前的状态大，还是现在的状态大
        }
        return dp[n];
    }
};
// @lc code=end

