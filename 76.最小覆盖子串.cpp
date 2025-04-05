/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {//unordered_map做哈希
        int n=s.size();
        unordered_map<int,int> num;//哈希

        int cnt=t.size();//所需长度
        for (int i=0;i<cnt;i++) num[t[i]]++;

        //答案所需变量
        int res=INT_MAX;//因为是最小滑窗
        int st=0;

        for (int i=0,j=0;i<n;i++) {//遍历s
            if (num[s[i]]>0) cnt--;//检查s的当前字符。合要求的话需求量减少。
            num[s[i]]--;//加入窗口，攒着s已经有的字符数量

            if (cnt==0) {//如果满足了t的要求
                while (j<i && num[s[j]]<0) {//移动窗口左边界。求满足要求的最小长度。存货num减少
                    num[s[j]]++;
                    j++;
                }
                //得到了满足条件的最短窗口。尝试更新
                if (res>i-j+1) {
                    res=i-j+1;
                    st=j;
                }
                //增加需求，寻找下一个合法序列。
                num[s[j]]++;
                cnt++;
                j++;
            }
        }
        return res==INT_MAX ? "" : s.substr(st,res);
    }
};
// @lc code=end









class Solution {
    public:
        string minWindow(string s, string t) {//数组做哈希
            int n=s.size();
            vector<int> num(128,0);//ascii码0:48-57，A65-90，a97-122。计数数组做哈希。
            for (char c:t) {//范围for
                num[c]++;//
            }
            int cnt=t.size();//子串需要的数量
    
            //答案所需的变量
            int res=INT_MAX;//最小滑窗长度
            int st=0;//最小滑窗起点
    
            for (int i=0,j=0;i<n;i++) {//窗口指针i，j。顺序遍历字符串s
                if (num[s[i]]>0) cnt--;//所需字符数量-1
                num[s[i]]--;//对应计数数组-1
                if (cnt==0) {//窗口中包含所有所需字符
                    while (j<i && num[s[j]]<0) {//窗口左指针右移（保证仍包含所有所需字符串）
                        num[s[j]]++;
                        j++;
                    }//这样就得到了当前的最小窗口
                    // res=min(res,i-j+1);//从0开始，故+1
                    if (res>i-j+1) {//更新答案
                        res=i-j+1;
                        st=j;
                    }
                    num[s[j]]++;//左边界右移。令当前序列不合法。去找下一个合法序列
                    j++;
                    cnt++;
                }
            }
            return res==INT_MAX ? "" : s.substr(st,res);//substr截取字符串，左闭右开，参数为(起点，长度)
        }
    };