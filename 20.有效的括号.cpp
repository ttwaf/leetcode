/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.length();i++) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                st.push(s[i]);
            } else if (s[i]==')') {
                if (st.top()!='(') return false;
                else st.pop();
            } else if (s[i]==']') {
                if (st.top()!='[') return false;
                else st.pop();
            } else if (s[i]=='}') {
                if (st.top()!='{') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

