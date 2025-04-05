/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {//dp版
public:
    int fib(int n) {
        if (n<=1) return n;
        vector<int> dp(n+1);//第i个的数值是dp[i]
        dp[0]=0;//初始化
        dp[1]=1;
        for (int i=2;i<=n;i++) {
            dp[i]=dp[i-1]+dp[i-2];//递推公式
        }
        return dp[n];
    }
};
// @lc code=end

class Solution {//递归版
    public:
        int fib(int n) {
            if (n==0) return 0;
            if (n==1) return 1;
            return fib(n-1)+fib(n-2);
        }
    };