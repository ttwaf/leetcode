/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:

    vector<vector<string>> res;
    vector<string> path;

    void trace(string s, int idx) {
        if (idx>=s.size()) {//到size就已经是空的了。说明已经找完了从头开始截取的一组方案了
            res.push_back(path);
            return ;
        }

        for (int i=idx;i<s.size();i++) {
            if (judge(s,idx,i)) {//是回文串的话
                string str=s.substr(idx,i-idx+1);//substr是左闭右开，故要+1
                path.push_back(str);
            } else continue;
            trace(s,i+1);
            path.pop_back();//弹出来。写递归后，你就当写第一层递归最后出来的时候
        }
        return ;
    }

    //双指针判断回文串
    bool judge(string s, int st, int end) {//双指针就是for循环的进化版
        for (int i=st,j=end;i<j;i++,j--) {
            if (s[i]!=s[j]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        trace(s,0);
        return res;
    }
};
// @lc code=end

