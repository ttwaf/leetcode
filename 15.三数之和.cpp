/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());//先排序
        vector<vector<int>> res;
        for (int i=0;i<n;i++) {//选一个数为起点，在这个数后面的范围选。
            if (nums[i]>0) return res;//剪枝。后面的数一定比这个数大。一定回不到0

            if (i>0 && nums[i]==nums[i-1]) continue;//去重，防止出现重复的二元组。
            
            //双指针
            int l=i+1;
            int r=n-1;
            while (l<r) {//左闭右闭。相等没意义。
                if (nums[i]+nums[l]+nums[r]>0) r--;//最大值变小点
                else if (nums[i]+nums[l]+nums[r]<0) l++;//最小值变大点
                else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    //再去重
                    while (l<r && nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;
                    //最后执行一次。
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

