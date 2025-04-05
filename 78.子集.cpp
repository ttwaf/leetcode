/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void trace(vector<int>& nums, int st) {

        res.push_back(path);//没有任何条件。就是遍历整棵树。

        for (int i=st;i<nums.size();i++) {
            path.push_back(nums[i]);
            trace(nums,i+1);
            path.pop_back();
        } 
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        trace(nums, 0);
        return res;
    }
};
// @lc code=end

