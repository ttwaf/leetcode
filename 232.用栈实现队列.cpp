/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    
    MyQueue() {//这个不用管
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        //如果输出栈是空的，就从输入栈移到输出栈弹出
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();//先保存再弹出
        stOut.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();//代码复用
        stOut.push(res);//弹出了，再推回去。
        return res;
    }
    
    bool empty() {//判空：输出栈和输入栈模拟一整个队列。队列的判空就是两个一起判空
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

