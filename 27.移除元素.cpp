/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {//二刷
public:
    int removeElement(vector<int>& nums, int val) {
        //快慢指针.快指针遍历旧数组。慢指针复制旧数组，更新新数组。
        int n=nums.size();
        int j=0;
        for (int i=0;i<n;i++) {
            if (nums[i]!=val) {
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};
// @lc code=end












class Solution {//一刷
    public:
        int removeElement(vector<int>& nums, int val) {
            int n=nums.size();
            int j=0;
            for (int i=0;i<n;i++) {
                if (nums[i]!=val) {
                    nums[j++]=nums[i];
                }
            }
            return j;
        }
    };