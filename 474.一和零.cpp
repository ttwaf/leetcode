/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //一个一个放入物品，遍历物品
        //有两个维度。0的数量和1的数量。在遍历时统计即可
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        //对当前字符串而言：
        for (string s:strs) {
            int m1=0,n1=0;
            for (char c:s) {
                if (c=='0') m1++;
                else n1++;
            }

            for (int i=m;i>=m1;i--) {//如果空间不够了，就不遍历了
                for (int j=n;j>=n1;j--) {//遍历背包容量，从后往前遍历
                    dp[i][j]=max(dp[i][j],dp[i-m1][j-n1]+1);//腾出当前0子串1容量的空间，维护更新
                }
            }
            
        }
        return dp[m][n];
    }
};
// @lc code=end

