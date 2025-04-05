/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //快慢指针
        int n=nums.size();
        int j=0;
        for (int i=0;i<n;i++) {
            if (nums[i]!=0) {
                nums[j++]=nums[i];
            }
        }
        for (int i=j;i<n;i++) nums[i]=0;
    }
};
// @lc code=end

