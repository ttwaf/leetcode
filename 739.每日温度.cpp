/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {//精简写法
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n,0);
        stack<int> st;//栈底到栈顶递减。
        st.push(0);//把第一个塞进去，防空
        for (int i=1;i<n;i++) {//按顺序遍历的
            while (!st.empty()&&temperatures[st.top()]<temperatures[i]) {
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            int n=temperatures.size();
            vector<int> res(n,0);
            stack<int> st;//栈底到栈顶递减。
            st.push(0);//把第一个塞进去，防空
            for (int i=1;i<n;i++) {
                if (temperatures[st.top()]>=temperatures[i]) st.push(i);//一直没遇到更高的温度，就入栈
                else {//遇到了更高的温度。对每个位置记下 下一个更高的温度。因为进去了之后可能乱序了
                    while (!st.empty() && temperatures[st.top()]<temperatures[i]) {
                        res[st.top()]=i-st.top();
                        st.pop();
                    } 
                    st.push(i);
                }
            }
            return res;
        }
    };