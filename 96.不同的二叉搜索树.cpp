/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=i;j++) {//轮流以j为子树节点(减掉了一个根节点)，加在一起
                dp[i]+=dp[j-1]*dp[i-j];//左边的情况乘右边的情况
            }
        }
        return dp[n];
    }
};
// @lc code=end

