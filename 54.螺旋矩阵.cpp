/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size()==0) return ans;//为空
        //赋值上下左右边界
        int u=0;
        int d=matrix.size()-1;
        int l=0;
        int r=matrix[0].size()-1;//要到头。循环里会额外留一个。
        while (l<r && u<d) {
            //循环左闭右开。每行留一个作为下一步的起点。
            for (int j=l;j<r;j++) ans.push_back(matrix[u][j]);//上行
            for (int i=u;i<d;i++) ans.push_back(matrix[i][r]);//右列
            for (int j=r;j>l;j--) ans.push_back(matrix[d][j]);//下行
            for (int i=d;i>u;i--) ans.push_back(matrix[i][l]);//左列
            //成对相加减。四个边界同时往内缩。留下相等的情况单独讨论。
            //偶数。则会在相邻后错开。奇数，则会在相邻后相等。只要其中一对相等就会退出循环。
            //若同时奇数。则就剩一行了，就只需要补充一次
            u++;
            l++;
            d--;
            r--;
        }
        //相等时，不用为下一个留个开头了。所以左闭右闭。
        if (l==r) for (int i=u;i<=d;i++) ans.push_back(matrix[i][l]);
        //若同时奇数，则只需要补充一次。所以用else
        else if (u==d) for (int j=l;j<=r;j++) ans.push_back(matrix[u][j]);
        return ans;
    }
};
// @lc code=end

