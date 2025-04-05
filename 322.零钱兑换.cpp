/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,__INT_MAX__);//dp[j]表和为j需要的最小硬币数

        dp[0]=0;//初值变成max了，所以要初始化

        for (int i=0;i<n;i++) {//遍历每一样物品
            for (int j=coins[i];j<=amount;j++) {
                if (dp[j-coins[i]]==__INT_MAX__) continue;//不加这句的话回报错
                dp[j]=min(dp[j],dp[j-coins[i]]+1);//腾出空间后，硬币数+1
            }
        }
        if (dp[amount]==__INT_MAX__) return -1;//如（3，2），要和为4的话，1永远不会出现，不会用到，永远是INT_MAX
        return dp[amount];
    }
};
// @lc code=end

