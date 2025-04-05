/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for (int i=0;i<stones.size();i++) {
            sum+=stones[i];
        }
        int tg=sum/2;//以一半为背包最大容量，看它装的满不。装的满最好，装不满也能求出最大
        
        vector<int> dp(1501,0);//物品是石头，重量是石头重量，价值也是石头重量
        for (int i=0;i<stones.size();i++) {
            for (int j=tg;j>=stones[i];j--) {
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        //分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。
        return sum-dp[tg]-dp[tg];
    }
};
// @lc code=end

