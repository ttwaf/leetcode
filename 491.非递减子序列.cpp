/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {//用数组去重
public:

    vector<vector<int>> res;
    vector<int> path;

    void trace(vector<int>& nums, int st) {

        if (path.size()>1) res.push_back(path);//遍历所有节点。不返回。

        // unordered_set<int> uset;
        int used[201]={0};//每层新建一个，用于本层去重
        for (int i=st;i<nums.size();i++) {
            if ((!path.empty() && nums[i]<path.back()) //排除不递增的情况
                || used[nums[i]+100])//nums[]范围为[-100,100],加了之后变成[0,200]一共201个
                continue;
            // uset.insert(nums[i]);
            used[nums[i]+100]++;
            path.push_back(nums[i]);
            trace(nums,i+1);
            path.pop_back();
        }
        return ;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        trace(nums,0);
        return res;
    }
};
// @lc code=end

class Solution {//用uset去重
    public:
    
        vector<vector<int>> res;
        vector<int> path;
    
        void trace(vector<int>& nums, int st) {
    
            if (path.size()>1) res.push_back(path);//遍历所有节点。不返回。
    
            unordered_set<int> uset;//每层新建一个，用于本层去重
            for (int i=st;i<nums.size();i++) {
                if ((!path.empty() && nums[i]<path.back()) //排除不递增的情况
                    || uset.find(nums[i])!=uset.end())//找到了说明之前用过了，同样不行。下一层可以用，但在本层不能用
                    continue;
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                trace(nums,i+1);
                path.pop_back();
            }
            return ;
        }
    
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            trace(nums,0);
            return res;
        }
    };