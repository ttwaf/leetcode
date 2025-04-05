/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void search(vector<int>& nums,vector<bool>& used) {

        if (nums.size()==path.size()) {
            res.push_back(path);
            return ;
        }

        for (int i=0;i<nums.size();i++) {
            //同一层，同一位置不能重复出现。不然回出现重复组合。树层去重
            if (i>0 && nums[i]==nums[i-1] && used[i-1]==false) continue;
            if (used[i]==false) {//防止取数取重复。因每次都是从0开始，所以上一层的已经用过的会是true。
                used[i]=true;
                path.push_back(nums[i]);
                search(nums,used);
                used[i]=false;
                path.pop_back();
            }
        }
        return ;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        search(nums,used);
        return res;
    }
};
// @lc code=end

class Solution {
    public:
        vector<vector<int>> res;
        vector<int> path;
    
        void search(vector<int>& nums, vector<bool>& used) {
    
            if (nums.size()==path.size()) {
                res.push_back(path);
                return ;
            }
    
            for (int i=0;i<nums.size();i++) {
                // if (i>0 && nums[i-1]==nums[i] && used[i-1]==true) continue;//如果相同数字在这条路径之前用过了
                // if (i>0 && nums[i-1]==nums[i] && used[i-1]==false) continue;//如果相同数字在这层递归之前用过了
                if (used[i]==false) {//如果这一位没用过，才能放进来。排除掉自身
                    used[i]=true;
                    path.push_back(nums[i]);
                    search(nums,used);
                    used[i]=false;
                    path.pop_back();
                }
            }
            return ;
        }
    
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<bool> used(nums.size(),false);
            search(nums,used);
            return res;
        }
    };