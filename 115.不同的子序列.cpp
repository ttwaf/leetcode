/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(m+1,0));
        //母串以i-1结尾，子串以j-1结尾，的子序列最大个数
        for (int i=0;i<n;i++) dp[i][0]=1;//子串是空串。母串都是1
        for (int j=1;j<m;j++) dp[0][m]=0;//母串是空串，故无论多少都是0
        //从第一个开始比对
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];//连续两个相同的话，可以用上一层循环的
                else dp[i][j]=dp[i-1][j];//沿用上一层循环的
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

