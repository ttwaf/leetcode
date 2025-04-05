/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    int sum=0;
    void trace(vector<int>& candidates, int target, int idx, int sum) {
        // if (sum>target) return ;//剪枝.也可以放在for循环里面剪

        if (sum==target) {
            res.push_back(path);
            return ;
        }

        for (int i=idx;i<=candidates.size() && sum+candidates[i]<=target;i++) {
            sum+=candidates[i];
            path.push_back(candidates[i]);
            trace(candidates,target,i,sum); //可以重复读取，不用+1.每层递归把上一层的排除在集合之外
            sum-=candidates[i];
            path.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());//放在for循环里剪枝需要排序
        trace(candidates, target, 0, sum);
        return res;
    }
};
// @lc code=end

class Solution {
    public:
    
        vector<vector<int>> res;
        vector<int> path;
        int sum=0;
        void trace(vector<int>& candidates, int target, int idx, int sum) {
            if (sum>target) return ;//剪枝.也可以放在for循环里面剪跳过递归更优化
    
            if (sum==target) {
                res.push_back(path);
                return ;
            }
    
            for (int i=idx;i<candidates.size();i++) {
                sum+=candidates[i];
                path.push_back(candidates[i]);
                trace(candidates,target,i,sum); //可以重复读取，不用+1.每层递归把上一层的排除在集合之外
                path.pop_back();
                sum-=candidates[i];
            }
            return ;
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            trace(candidates, target, 0, sum);
            return res;
        }
    };