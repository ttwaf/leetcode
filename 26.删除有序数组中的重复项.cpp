/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //快慢指针
        int n=nums.size();
        int j=1;
        for (int i=1;i<n;i++) {//0不用用到。所以都从0开始遍历。
            if (nums[i]!=nums[i-1]) {
                nums[j++]=nums[i];
            }
        }
        nums.resize(j+1);
        return j;
    }
};
// @lc code=end

