/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> cnt;//用哈希存果树种类
        int res=0;//果树长度。
        for (int i=0,j=0;i<n;i++) {//顺序遍历每棵果树.两个窗口指针
            cnt[fruits[i]]++;
            while (cnt.size()>2) {//种类超过2之后，就往外扔水果。不同种类的水果都有可能扔
                cnt[fruits[j]]--;
                if (cnt[fruits[j]]==0) cnt.erase(fruits[j]);//扔完了就删除一个水果种类
                j++;//扔一个，指针右移一位
            }
            res=max(res,i-j+1);//从0开始，故长度为i-j+1
        }
        return res;
    }
};
// @lc code=end

