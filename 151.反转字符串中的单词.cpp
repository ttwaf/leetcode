/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:

    void reverse(string& s,int st,int end) {//左闭右闭。相减就是长度
        for (int i=st,j=end;i<j;i++,j--) {
            swap(s[i],s[j]);
        }
    }

    void rmspace(string& s) {//看代码顺序是：先走一个while（第一个单词），再加空格，再走完最后一个单词
        int j=0;//j指向新数组（慢指针），i指向旧数组（快指针）
        for (int i=0;i<s.size();i++) {
            if (s[i]!=' ') {//在每个单词的开头处开始。消除了前置空格
                if (j!=0) s[j++]=' ';//2复制完单词之后加后置空格。
                while (i<s.size() && s[i]!=' ') {//1复制单词。
                    s[j++]=s[i++];
                }
            }
        }
        s.resize(j);
    }

    string reverseWords(string s) {
        //1、删除多余空格。2、反转整个字符串。3、反转单词
        rmspace(s);
        reverse(s,0,s.size()-1);

        //开始反转单词
        int j=0;//慢指针
        for (int i=0;i<=s.size();i++) {//快指针
            if (s[i]==' ' || i==s.size()) {//到一个单词结束或者末尾之后一格
                reverse(s,j,i-1);
                j=i+1;
            }
        }
        return s;
    }
};
// @lc code=end


