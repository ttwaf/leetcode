/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;//双指针左闭右闭。
        int ans=0;
        while (l<=r) {//左闭右闭，相等时区间有效
            int m=l+(r-l)/2;//防溢出
            if ((long long)m*m==x) return m;//看范围。[ (2^31-1)/2 ]^2 会爆的
            else if ((long long)m*m<x) {
                ans=m;//小数部分会被舍去。所以放在这边。
                l=m+1;
            } 
            else r=m-1;
        }
        return ans;
    }
};
// @lc code=end

