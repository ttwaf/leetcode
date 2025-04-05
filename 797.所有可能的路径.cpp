/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<vector<int>>& graph,int s) {
        if (s==graph.size()-1) {
            res.push_back(path);
            return ;
        }

        for (int i=0;i<graph[s].size();i++) {//遍历其它点
            path.push_back(graph[s][i]);
            dfs(graph,graph[s][i]);
            path.pop_back();
            
        }
        return ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        //从起点开始遍历。
        path.push_back(0);
        dfs(graph,0);
        return res;
    }
};
// @lc code=end

