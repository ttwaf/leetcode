/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {//删除的做法
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector(m+1,0));
        //表以i-1,j-1结尾要删的最小个数
        //初始化
        for (int i=1;i<=n;i++) dp[i][0]=i;//另一个为空串。则需要全删了
        for (int j=1;j<=m;j++) dp[0][j]=j;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];//相同就不用删。继承上一位的操作
                else dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);//不相等的话就删掉
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

class Solution {//最长公共子序列做法
    public:
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<vector<int>> dp(n+1,vector(m+1,0));
    
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                    if (word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return n+m-2*dp[n][m];//不是公共子序列的部分都删掉
        }
    };