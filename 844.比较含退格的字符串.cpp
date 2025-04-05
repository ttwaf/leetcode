/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //双指针从后向前遍历
        int i=s.size()-1;
        int j=t.size()-1;
        int s1=0,t1=0;//代表两个字符串'#'的数量
        while (1) {
            while (i>=0) {//从后往前遍历
                if (s[i]=='#') s1++;//记录退格数
                else {//如果不是退格
                    if (s1>0) s1--;//退格发挥作用
                    else break;//没有退格了，要比较了
                }
                i--;//遍历i的做法
            }
            while (j>=0) {
                if (t[j]=='#') t1++;
                else {//如果不是退格
                    if (t1>0) t1--;
                    else break;//没有退格了。要比较了
                }
                j--;
            }
            //下面是主逻辑。上面是处理退格的逻辑
            if (i<0 || j<0) break;//遍历完了至少一个。在这是整个while的出口
            
            if (s[i]!=t[j]) return false;//直接判断
            i--;
            j--;
        }
        if (i==-1 && j==-1) return true;
        else return false;//一方有剩余是即为false
    }
};
// @lc code=end

