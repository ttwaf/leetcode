/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int loop=n/2;//每次循环走两行两列
        vector<vector<int>> res(n,vector<int>(n,0));
        int sx=0,sy=0;//每次循环起始位置
        int ofst=1;//每次循环结束位置偏移量。左闭右开。
        int cnt=1;//从1开始赋值
        while (loop--) {
            int i=sx,j=sy;
            for (;j<n-ofst;j++) {//上行。横着更新用j，竖着更新用i
                res[i][j]=cnt++;
            }
            for (;i<n-ofst;i++) {//右列
                res[i][j]=cnt++;
            }
            for (;j>sy;j--) {//下行。注意起始闭，结束开。始终左闭右开。
                res[i][j]=cnt++;
            }
            for (;i>sx;i--) {//左列
                res[i][j]=cnt++;
            }
            //更新起始位置
            sx++;
            sy++;
            //更新结束位置偏移量。
            ofst++;
        }
        //中心单独处理
        if (n%2!=0) res[sx][sy]=cnt;
        return res;
    }
};
// @lc code=end


//一刷
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int loop=n/2;//圈数。一次循环走两行两列。最后的中心单独处理
            vector<vector<int>> res(n,vector<int>(n,0));
            int i=0,j=0;//行和列
            int sx=0,sy=0;//每次循环的起始位置
            int t=1;//每次循环结束的偏移量
            int cnt=1;//赋值的量
            //给了n，这个n是长度，可以直接用
            while (loop--) {//一次循环走上行，右列，下行，左列。
                i=sx,j=sy;
                //全都左闭右开
                for (;j<n-t;j++) {
                    res[i][j]=cnt++;
                }
                for (;i<n-t;i++) {
                    res[i][j]=cnt++;
                }
                for (;j>sx;j--) {
                    res[i][j]=cnt++;
                }
                for (;i>sy;i--) {
                    res[i][j]=cnt++;
                }
                //起始位置（头）更新
                sx++;
                sy++;
                //偏移量更新（导致尾更新）
                t++;
            }
            if (n%2!=0) res[sx][sy]=cnt;
            return res;
        }
    };
