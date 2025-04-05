/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n<=1) return 1;//定义dp的时候用到了n，n要是=0的话，下面初始化dp[2]就会出错
        vector<int> dp(3);//到i阶有dp[i]种方法
        dp[1]=1;
        dp[2]=2;
        for (int i=3;i<=n;i++) {
            //从前两个状态推出第三个状态
            int sum=dp[1]+dp[2];
            dp[1]=dp[2];//第一个状态变成第二个状态
            dp[2]=sum;//第二个状态变成下一个状态
        }
        return dp[2];
    }
};
// @lc code=end

class Solution {//正常版
    public:
        int climbStairs(int n) {
            if (n<=1) return 1;//定义dp的时候用到了n，n要是=0的话，下面初始化dp[2]就会出错
            vector<int> dp(n+1);//到i阶有dp[i]种方法
            dp[1]=1;
            dp[2]=2;
            for (int i=3;i<=n;i++) {
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
    };