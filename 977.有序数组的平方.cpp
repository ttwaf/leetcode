/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //用双指针之相向指针。
        int n=nums.size();
        vector<int> res(n,0);
        int k=n-1;//设一个指向res的指针。从后往前走。
        for (int i=0,j=n-1;i<=j;) {//两个指针是分开走的，指针相邻时，可能一个走过了另一个没走过。所以要相等。
            if (nums[i]*nums[i]<nums[j]*nums[j]) {//用小于号保持排序稳定性。保证相等时i在前，j在后
                res[k--]=nums[j]*nums[j];//保留大的。故从后往前写res
                j--;//更新表达式放在循环体里面
            } else {
                res[k--]=nums[i]*nums[i];
                i++; 
            }
        }
        return res;
    }
};
// @lc code=end















//一刷
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n=nums.size();
            int k=n-1;
            vector<int> res(n,0);//赋n个0
            for (int i=0,j=n-1;i<=j;) {
                if (nums[i]*nums[i]<nums[j]*nums[j]) {
                    res[k--]=nums[j]*nums[j];
                    j--;
                } else {
                    res[k--]=nums[i]*nums[i];
                    i++;
                }
            }
            return res;
        }
    };