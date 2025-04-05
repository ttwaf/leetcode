/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

    string m[10]={
        "","","abc","def","ghi","jkl",
        "mno","pqrs","tuv","wxyz"
    };

    vector<string> res;
    void trace(string digits, int idx,string path) {//idx是树的深度，也是递归的层数

        if (idx==digits.size()) {//表示树的深度。
            res.push_back(path);//会有空串的情况
            return ;
        }

        // int num=stoi(digits[idx]);//转为数字
        int num = digits[idx]-'0';
        string s=m[num];//取出数字对应集合.接下来遍历集合
        for (int i=0;i<s.length();i++) {//遍历的是集合
            trace(digits,idx+1,path+s[i]);
        }
        return ;
    }

    vector<string> letterCombinations(string digits) {
        if (digits=="") return res;//防止空串的情况
        trace(digits,0,"");//从0下表开始取集合。
        return res;
    }
};
// @lc code=end

class Solution {
    public:
    
        string m[10]={
            "","","abc","def","ghi","jkl",
            "mno","pqrs","tuv","wxyz"
        };
    
        vector<string> res;
        string path;
        void trace(string digits, int idx) {//idx是树的深度，也是递归的层数
    
            if (idx==digits.size()) {//表示树的深度。
                res.push_back(path);//会有空串的情况
                return ;
            }
    
            // int num=stoi(digits[idx]);//转为数字。这种写法不行。还是换成下面的写法
            int num = digits[idx]-'0';
            string s=m[num];//取出数字对应集合.接下来遍历集合
            for (int i=0;i<s.length();i++) {//遍历的是集合
                path.push_back(s[i]);
                trace(digits,idx+1);
                path.pop_back();
            }
            return ;
        }
    
        vector<string> letterCombinations(string digits) {
            if (digits=="") return res;//防止空串的情况
            trace(digits,0);//从0下表开始取集合。
            return res;
        }
    };