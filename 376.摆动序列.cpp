/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
//导致它不成立的条件是什么？
    int wiggleMaxLength(vector<int>& nums) {
        int n=0;
        sort(nums.begin(),nums.end());
        for (int i=0,j=nums.size()-1;i<j;i++,j--) {
            if (i==j) cout<<nums[i];
            cout<<nums[i]<<" "<<nums[j]<<" ";
        }
        // for (int i:nums) cout<<i<<" ";
        return n;
    }
};
// @lc code=end

