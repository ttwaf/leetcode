/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for (int i=0;i<n;i++) sum+=nums[i];
        int x=(sum+target)/2;//x为正数和
        if ((sum+target)%2==1) return 0;//必须是偶数
        if (abs(target)>sum) return 0;//目标和超过最大和，也不可能

        //接下来就是装满容量为x的背包，
        //原本是全都要装，只是哪个正哪个负。现在转化为挑哪些为正即可。
        vector<int> dp(x+1,0);//只需要用到x
        //dp[j]表示和为j的话有dp[j]种方法。
        dp[0]=1;//和为0的话就不取数

        for (int i=0;i<n;i++) {
            for (int j=x;j>=nums[i];j--) {//环环相扣
                dp[j]+=dp[j-nums[i]];//从上一轮中再腾出nums[i]的空间来累加
            }
        }
        return dp[x];
    }
};
// @lc code=end

