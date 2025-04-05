/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));//dp[i][j]表示到(i,j)位置有几条路径
        //初始化:到边界都只有一条路径
        for (int i=0;i<m;i++) dp[i][0]=1;
        for (int j=0;j<n;j++) dp[0][j]=1;
        for (int i=1;i<m;i++) {//从0开始的都初始化过了。接下来从1开始
            for (int j=1;j<n;j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

