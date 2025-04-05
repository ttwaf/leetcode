/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;//key:a+b的数值，value:a+b数值出现的次数
        for (int a:nums1) {
            for (int b:nums2) {
                mp[a+b]++;
            }
        }

        int cnt=0;
        for (int c:nums3) {
            for (int d:nums4) {
                if (mp.find(0-c-d)!=mp.end()) {
                    cnt+=mp[0-c-d];//方案数累加
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

