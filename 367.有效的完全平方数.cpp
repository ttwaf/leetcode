/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0,r=num;//左闭右闭
        while (l<=r) {//左闭右闭，相等时区间有效
            int m=l+(r-l)/2;//l很接近右边范围极限的时候，l+r会爆。所以这里防溢出
            if ((long long)m*m==num) return true;//会爆。
            else if ((long long)m*m<num) l=m+1;
            else r=m-1;
        }
        return false;
    }
};
// @lc code=end

