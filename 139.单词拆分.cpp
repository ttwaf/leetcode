/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());//把一个个单词看成一个个元素。方便查找

        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;//空字符串存在。这样后面遍历的条件才能成立

        //这个遍历字符串也是很暴力了
        for (int i=1;i<=n;i++) {//一个个字母看成一个个空间
            for (int j=0;j<i;j++) {//一个个单词看成一个个物品
                string str=s.substr(j,i-j);//substr(起始位置，截取的个数)
                if (st.find(str)!=st.end() && dp[j]) {//如果有这个词并且前半部分也是个词的话
                    dp[i]=true;//到目前为止都可以成立
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

