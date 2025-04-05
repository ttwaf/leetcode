/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
        }
        //能分成两个相同的子集，一定是偶数
        if (sum%2==1) return false;
        int tg=sum/2;

        vector<int> dp(20001,0);//物品是数值，重量w是数值，价值v也是数值
        //滚动数组不用初始化
        for (int i=0;i<nums.size();i++) {
            for (int j=tg;j>=nums[i];j--) {
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if (dp[tg]==tg) return true;
        else return false;
    }
};
// @lc code=end

