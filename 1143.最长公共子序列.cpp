/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //a以i-1结尾，b以j-1为结尾的最长公共子序列的长度

        int res=0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

