/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {//初始化版
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //表以a数组以i结尾,b数组以j结尾的最长重复子数组的长度

        //因为不会遍历到，所以独立出来初始化
        for (int i=0;i<n;i++) if (nums1[i]==nums2[0]) dp[i][0]=1;
        for (int j=0;j<m;j++) if (nums1[0]==nums2[j]) dp[0][j]=1;

        int res=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {//从后往前遍历，才能保证用上一层遍历的东西。
                //注意这里条件变了
                if (nums1[i]==nums2[j] && i>0 && j>0) dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

class Solution {//滚动数组版
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            int n=nums1.size();
            int m=nums2.size();
            vector<int> dp(n+1,0);
            int res=0;
            for (int i=1;i<=n;i++) {
                for (int j=m;j>=1;j--) {//从后往前遍历，才能保证用上一层遍历的东西。
                    if (nums1[i-1]==nums2[j-1]) dp[j]=dp[j-1]+1;
                    else dp[j]=0;//防止影响到下下层
                    res=max(res,dp[j]);
                }
            }
            return res;
        }
    };

class Solution {//二维数组版
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            int n=nums1.size();
            int m=nums2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            //表示到i-1，j-1为止的最长重复子数组。
    
            int res=0;
            //连续的，就理解为遍历两个一维的。
            int i=0,j=0;
            for (i=1;i<=n;i++) {//遍历a数组
                for (j=1;j<=m;j++) {//遍历b数组
                    if (nums1[i-1]==nums2[j-1]) dp[i][j]=dp[i-1][j-1]+1;//连续的。前一个一定在左上角
                    res=max(res,dp[i][j]);
                }
            }
            return res;
        }
    };