/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {//自写reverse版
public:
//左闭右闭，用的时候就要减一
void reverse(string& s,int st,int end) {
    for (int i=st,j=end;i<j;i++,j--) {//双指针：奇最后指向同一个，不做处理。偶刚刚好
        swap(s[i],s[j]);
    }
}

    string reverseStr(string s, int k) {
        for (int i=0;i<s.size();i+=2*k) {//固定规律，改变循环区间即可。
            //对每个区间都是这个循环
            if (i+k<=s.size()) {//够k个，无论是否到了2k个，都直接反转前k个
                reverse(s,i,i+k-1);//左闭右闭，故加长度减一
            } else {//不够k个，就反转到底。
                reverse(s,i,s.size()-1);//左闭右闭，故加长度减一
            }
        }
        return s;
    }
};
// @lc code=end

class Solution {//用reverse版
    public:
        string reverseStr(string s, int k) {
            for (int i=0;i<s.size();i+=2*k) {//固定规律，改变循环区间即可。
                //对每个区间都是这个循环
                if (i+k<=s.size()) {//够k个，无论是否到了2k个，都直接反转前k个
                    reverse(s.begin()+i,s.begin()+i+k);
                } else {//不够k个，就反转到底。
                    reverse(s.begin()+i,s.end());
                }
            }
            return s;
        }
    };