/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //定义一个栈来运算。用longlong
        stack<long long> st;
        for (int i=0;i<tokens.size();i++) {//遍历字符串
            if (tokens[i]=="+" || tokens[i]=="-"  
            || tokens[i]=="*" || tokens[i]=="/") {//是操作符则对子表达式进行处理
                //后缀表达式一定有效保证了运算符前一定有操作数，所以不用手动排除empty的情况
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i]=="+") st.push(num2+num1);
                if (tokens[i]=="-") st.push(num2-num1);
                if (tokens[i]=="*") st.push(num2*num1);
                if (tokens[i]=="/") st.push(num2/num1);
                
            } else {//可以先写else(处理的前提)，再写if(处理的重点).是操作数则入栈
                st.push(stoll(tokens[i]));
            }
        }
        return st.top();
    }
};
// @lc code=end

