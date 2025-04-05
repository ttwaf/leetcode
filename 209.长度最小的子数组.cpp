/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;//窗口之和。
        int len=0;//窗口长度。
        int res=INT_MAX;//用res维护len返回值
        for (int i=0,j=0;i<n;i++) {//i为快指针（右框），j为慢指针（左框）
            sum+=nums[i]; 
            while (sum>=target) {//维护窗口之和
                len=i-j+1;//左闭右闭不是关键。从0开始才是重点。从0开始要+1.
                res=min(res,len);
                sum-=nums[j++];//窗口左框右移
            }
        }
        return res==INT_MAX?0:res;//返回最小长度。注意当res值为极大值是说明没有数组，要返回0
    }
};
// @lc code=end




















//一刷
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n=nums.size();
            int i=0,j=0;
            int sum=0;
            int len=0;
            int res=INT_MAX;
            for (i=0,j=0;i<n;i++) {
                sum+=nums[i];
                while (sum>=target) {
                    len=i-j+1;
                    res=res<len?res:len;
                    sum-=nums[j++];
                }
            }
            return res==INT_MAX?0:res;
        }
    };