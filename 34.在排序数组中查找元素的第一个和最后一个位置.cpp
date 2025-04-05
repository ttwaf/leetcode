/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    //找右边界
    int rfind(vector<int>& nums,int target) {
        int n=nums.size();
        int l=0,r=n-1;//根据题意，左闭右闭比较好。
        int rb=-2;//预设找不到。正常可能走到-1去的。所以用-2
        while (l<=r) {//左闭右闭，相等时有意义。
            int mid=l+(r-l)/2;//防溢出
            //永远想象l在最左，r在最右，mid在最中间，再根据大于小于来判断target在左区间还是右区间，就比较快
            if (nums[mid]>target) {//target在左区间。相等不在这边，这边是右边界。所以找的是右边界
                r=mid-1;
            } else {//相等在这边。相等时l会继续右移。所以找的是右边界
                l=mid+1;
                rb=l;
            }//左闭右闭。最后l>r，所以l==rb要减一个回去。因为最后一次循环l==r，r在区间外。要回到区间
        }
        return rb;
    }
    //找左边界
    int lfind(vector<int>& nums,int target) {
        int n=nums.size();
        int l=0,r=n-1;//左闭右闭
        int lb=-2;
        while (l<=r) {//相等时有意义
            int mid=l+(r-l)/2;
            if (nums[mid]<target) l=mid+1;//target在右边界。等号不在这。找的就是它，l指针左边界
            else {
                r=mid-1;
                lb=r;
            }//左闭右闭。最后l>r，lb==r要减一个回去。因为最后一次循环l==r,l在区间外，所以要减一个回去
        }
        return lb;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lfind(nums,target);
        int r=rfind(nums,target);
        if (l==-2 || r==-2) return {-1,-1};//某一边指针没更新过。说明在数组外
        if (r-1>=l+1) return {l+1,r-1};//在数组内找到了。
        return {-1,-1};//数组内没找到

    }
};
// @lc code=end

