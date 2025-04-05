/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26];
        for (int i=0;i<magazine.size();i++) cnt[magazine[i]-'a']++;
        for (int i=0;i<ransomNote.size();i++) {
            cnt[ransomNote[i]-'a']--;
        }
        for (int i=0;i<26;i++) {
            if (cnt[i]<0) return false;
        }
        return true;
    }
};
// @lc code=end

