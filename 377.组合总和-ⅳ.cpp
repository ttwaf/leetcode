/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    //请注意，顺序不同的序列被视作不同的组合。
    int combinationSum4(vector<int>& nums, int tg) {
        int n=nums.size();

        vector<unsigned int> dp(tg+1,0);

        dp[0]=1;

        for (int i=0;i<=tg;i++) {//和为tg.先遍历空间
            for (int j=0;j<n;j++) {//一个一个放入背包遍历。再遍历物品
                if (i>=nums[j])
                    dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[tg];
    }
};
// @lc code=end

