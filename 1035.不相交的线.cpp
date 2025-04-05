/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //以i-1，j-1为结尾的最长公共子序列长度

        int res=0;

        for (int i=1;i<=n;i++) {//遍历a数组
            for (int j=1;j<=m;j++) {//遍历b数组
                if (nums1[i-1]==nums2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

