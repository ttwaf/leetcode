/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;//key存数，value存下标
        for (int i=0;i<nums.size();i++) {
            //让两数之和变成找一个数。
            //一个一个遍历。找到了就进
            auto iter=mp.find(target-nums[i]);
            if (iter !=mp.end()) {//如果找到了，就返回二者的下标
                return {iter->second,i};
            } //没找到就放到map里去找。

            else mp.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};
// @lc code=end

