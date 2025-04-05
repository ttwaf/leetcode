/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i=0;i<m && obstacleGrid[i][0]==0;i++) dp[i][0]=1;//遇到障碍就停下
        for (int j=0;j<n && obstacleGrid[0][j]==0;j++) dp[0][j]=1;//遇到障碍就停下
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if (obstacleGrid[i][j]==0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end
class Solution {//之前的失败版
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacle.size();
        int n=obstacle[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i=0;i<m;i++) {
            if (obstacleGrid[i][0]==1) break;
            dp[i][0]=1;
        }
        for (int j=0;j<n;j++) {
            if (obstacleGrid[0][j]==1) break;
            dp[0][j]=1;
        }
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if (obstacleGrid[i-1][j]==0 && obstacleGrid[i][j-1]==0) {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
}