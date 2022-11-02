/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        for(int i=0; i<word1.size(); i++){
            a = a + word1[i];
        }
        string b = "";
        for(int i=0; i<word2.size(); i++){
            b = b + word2[i];
        }
        if(a == b) return true;
        else return false;
    }
};
// @lc code=end

