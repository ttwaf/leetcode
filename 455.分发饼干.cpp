/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {//g是胃口，s是饼干
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int num=0;
        int i=0;
        //对每个孩子来说，如果有最小的饼干够吃，就。。。？
        for (int j=0;j<s.size();j++) {
            if (s[j]>=g[i]) {
                num++;
                i++;//吃完就下一个。i可能越界的噢
            }
            if (i>=g.size()) break;
        }
        return num;
    }
};
// @lc code=end

class Solution {//失败版
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            int num=0;
            //对每个孩子来说，如果有最小的饼干够吃，就。。。？
            for (int i=0;i<s.size();i++) {
                for (int j=0;j<g.size();j++) {
                    if (g[j]>=s[i]) num++;
                }
            }
            return num;
        }
    };