/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for (int i=0;i<n;i++) {
            //一级剪枝去重
            if (nums[i]>target && nums[i]>=0) break;//和上一道题的区别是上一道题target确定==0
            if (i>0 && nums[i]==nums[i-1]) continue;//去重

            for (int j=i+1;j<n;j++) {
                //二级剪枝去重
                if (nums[i]+nums[j]>target && nums[i]+nums[j]>=0) break;
                if (j>i+1 && nums[j]==nums[j-1]) continue;

                //双指针。左闭右闭
                int l=j+1;
                int r=n-1;
                while (l<r) {//左闭右闭，相等没意义
                    if ((long)nums[i]+nums[j]+nums[l]+nums[r]>target) r--;
                    else if ((long)nums[i]+nums[j]+nums[l]+nums[r]<target) l++;
                    else {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l<r && nums[l]==nums[l+1]) l++;
                        while (l<r && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

