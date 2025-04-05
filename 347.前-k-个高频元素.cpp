/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    bool operator()(const pair<int,int>& a,const pair<int,int>& b) {
        return a.second>b.second;//大顶堆
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++) {
            mp[nums[i]]++;//把哈希当数组用
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Solution> que;
        for (unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {//用迭代器遍历
            que.push(*it);//迭代器当指针用。优先队列里存的是pair键值对
            if (que.size()>k) que.pop();
        }

        vector<int> res(k);//vector是动态的，一开始未知大小，故定个下限。不然报错
        for (int i=k-1;i>=0;i--) {//一步。直接把定义的哈希和优先队列拿来放进res
            res[i]=que.top().first;
            que.pop();
        }
        return res;
    }
};
// @lc code=end

