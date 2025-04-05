/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:

    vector<string> res;
    //在s自己身上做文章即可
    void trace(string s,int st,int num) {//num记录分割的次数

        if  (num==3) {//如果到三段了
            if (judge(s,st,s.size()-1)) {//第四段单独出来判断
                res.push_back(s);
            }
            return ;
        }

        
        for (int i=st;i<s.size();i++) {//分割前三段
            if (judge(s,st,i)) {//判断[st,i]这个区间的子串是否合法
                s.insert(s.begin()+i+1,'.');//s.begin和i都从0开始，故要+1
                num++;
                trace(s,i+2,num);//从逗号之后开始
                num--;
                s.erase(s.begin()+i+1);
            } else break;//不合法就直接结束
        }
        return ;
    }
    
    bool judge(string s,int st,int end) {//判断[st,end]所组成的数字是否合法
        if (st>end) return false;//如果后面没数字了也要停下。不然样例通不过。
        if (s[st]=='0' && st!=end) return false;//以0开头的非0数字不合法
        int num=0;
        for (int i=st;i<=end;i++) {
            if (s[i]>'9' || s[i]<'0') return false;//非数字不合法
            num=num*10+(s[i]-'0');
            if (num>255) return false;//越界不合法
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        trace(s,0,0);
        return res;
    }
};
// @lc code=end

