/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //母串i-1，子串j-1位置的最大子序列长度

        int res=0;
        for (int i=1;i<=n;i++) {//遍历母串t
            for (int j=1;j<=m;j++) {//遍历子串s
                if (t[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=dp[i-1][j];//继承母串的最大子序列长度。
                res=max(res,dp[i][j]);
            }
        }
        
        return res==m?true:false;
    }
};
// @lc code=end

