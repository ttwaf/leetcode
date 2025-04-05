/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();//左闭右开
        int l=0,r=n;//左闭右开
        while (l<r) {//l==r,[l,r)是无效区间
            // int mid=l+(r-l)/2;
            int mid=(l+r)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) l=mid+1;
            else r=mid;//保持无效区间。
        }
        return -1;
    }
};
// @lc code=end

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n=nums.size();
            int l=0,r=n-1;//定义左右指针。左闭右闭。
            while (l<=r) {//左闭右闭相等时是有效区间。l==r,[l,r]有效的。
                // int mid=l+(r-l)/2;
                int mid=(l+r)/2;//防止溢出
                if (nums[mid]==target) return mid;
                else if (nums[mid]<target) l=mid+1;
                else r=mid-1;
            }
            return -1;
        }
    };

//一刷
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n=nums.size();
            int low=0,high=n-1,mid=0;
            while (low<=high) {
                mid=(low+high)/2;
                if (nums[mid]==target) return mid;
                else if (nums[mid]<target)
                {
                    low=mid+1;
                }
                else if (nums[mid]>target)
                {
                    high=mid-1;
                }
            }
            return -1;
        }
    };