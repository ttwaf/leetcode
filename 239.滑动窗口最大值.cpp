/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class myqueue {
public:
    deque<int> que;

    void push(int k) {//主体一步。一个while维护单调性，弹出队尾
        while (!que.empty() && que.back()<k) {
            que.pop_back();
        }
        que.push_back(k);//插入窗口头
    }

    void pop(int k) {//一步。一个if弹出队头。
        if (!que.empty() && que.front()==k) {
            que.pop_front();
        }
    }

    int front() {//一步，直接返回
        return que.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myqueue que;
        vector<int> res;
        int n = nums.size();
        for (int i=0;i<k;i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i=k;i<n;i++) {//一步。用单调队列维护滑动窗口最值即可。
            que.push(nums[i]);
            que.pop(nums[i-k]);
            res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end
