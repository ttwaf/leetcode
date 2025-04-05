/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<unsigned int> dp(amount+1);

        dp[0]=1;//和为0就是不取硬币。有一种取法。

        for (int i=0;i<n;i++) {//对n种硬币一种种遍历
            for (int j=coins[i];j<=amount;j++) {
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

