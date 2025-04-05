/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        
        string res;//原字符串当栈，造一个新的来存放返回值
        for (char t:s) {
            if (res.empty() || res.back() != t) {//能放进去(不重复或者空)的话
                res.push_back(t);
            } else {
                res.pop_back();//重复则弹出
            }
        }
        return res;

    }
};
// @lc code=end

