/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    //已经确保了至少有一个能传进来。
    int robb(vector<int>& nums, int st,int end) {
        int n=end-st+1;//长度。
        vector<int> dp(n+1,0);

        if (n==1) return nums[st];//长度为2的话，for循环会自己停下。

        dp[st]=nums[st];
        dp[st+1]=max(nums[st],nums[st+1]);

        for (int i=st+2;i<=end;i++) {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];
        //初始化保证后面能用
        int l=robb(nums,0,n-2);
        int r=robb(nums,1,n-1);
        int res=max(l,r);
        return res;
        
    }
};
// @lc code=end

