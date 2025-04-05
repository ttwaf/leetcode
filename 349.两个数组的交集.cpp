/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums(nums1.begin(),nums1.end());//用迭代器，换个容器存储
        //用范围for遍历容器
        for (int i:nums2) {
            if (nums.find(i)!=nums.end()) {//找得到的话
                res.insert(i);
            }
        }
        return vector<int>(res.begin(),res.end());//临时容器。
    }
};
// @lc code=end

