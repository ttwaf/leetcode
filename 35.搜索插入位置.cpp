/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n;//左右指针。左闭右开
        while (l<r) {//l==r时区间无效
            int mid=l+(r-l)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) l=mid+1;
            else r=mid;//保持区间无效
        }

        return r;
    }
};
// @lc code=end

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int n=nums.size();
            int l=0,r=n-1;//定义左右指针。左闭右闭
            while (l<=r) {//相等时区间有效
                int mid=l+(r-l)/2;//防溢出
                if (nums[mid]==target) return mid;
                else if (nums[mid]<target) l=mid+1;
                else r=mid-1;//保持循环不变量
            }
            //找不到时有三种情况。1、最前：最后一次循环是[r-1,0==l]，
            // 2、中间，有两条分支，所以有两种情况：
            //最后一次循环可能是[r-1,mid==l](target在nums[mid]左边)，r在mid左边，要插在mid的位置，
            //也可能是[mid==r,l+1]（target在nums[mid]右边），要插在mid右边。
            // 3、最后：最后一次循环是[n-1==r,l]
            return r+1;
        }
    };