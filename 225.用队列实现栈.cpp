/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> que;

    MyStack() {//不用管
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        //要弹出最后一个元素，故要用到size
        int sz = que.size();
        sz--;//拷贝n-1个
        while (sz--) {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }
    
    int top() {
        //和pop差不多，但有区别，无法复用
        int sz = que.size();
        sz--;
        while (sz--) {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.push(que.front());
        que.pop();
        return res;
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

