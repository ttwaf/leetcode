/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:

    int get(int n) {
        int sum=0;
        while (n) {
            sum += (n%10)*(n%10);//只是拿出来。下一步再消掉
            n/=10;//每一位去右移
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> ust;
        while (1) {
            int sum=get(n);//求出每个位置上数字的平方
            //只有两种可能：1、是快乐数。2、进入了无限循环
            if (sum==1) return true;
            //还没无限循环的话就加入集合。
            if (ust.find(sum)!=ust.end()) return false;
            else ust.insert(sum);
            n=sum;//更新
        }
    }
};
// @lc code=end

