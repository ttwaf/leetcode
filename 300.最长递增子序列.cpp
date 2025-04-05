/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int res=1;
        vector<int> dp(n+1,1);//到i位置的最长递增子序列长度为dp[i].全部初始化为1
        for (int i=1;i<n;i++) {//逐个遍历序列
            for (int j=0;j<i;j++) {
                if (nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
            if (dp[i]>res) res=dp[i];//保留最长的那个。最后交出去
        }
        return res;
    }
};
// @lc code=end

