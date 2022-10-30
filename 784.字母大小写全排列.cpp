/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    void appendRes(string s, int i, int n){
        if(i >= n) return;
        if(s[i]>='a' && s[i]<='z'){
            appendRes(s, i+1, n);
            s[i] -= ('a'-'A');
            res.push_back(s);
            appendRes(s, i+1, n);
        }
        else if(s[i]>='A' && s[i]<='Z'){
            appendRes(s, i+1, n);
            s[i] += ('a'-'A');
            res.push_back(s);
            appendRes(s, i+1, n);
        }
        else{
            appendRes(s, i+1, n);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        if(n == 0) return res;
        res.push_back(s);
        if(s[0]>='a' && s[0]<='z'){
            appendRes(s, 1, n);
            s[0] -= ('a'-'A');
            res.push_back(s);
            appendRes(s, 1, n);
        }
        else if(s[0]>='A' && s[0]<='Z'){
            appendRes(s, 1, n);
            s[0] += ('a'-'A');
            res.push_back(s);
            appendRes(s, 1, n);
        }
        else{
            appendRes(s, 1, n);
        }
        return res;
    }
};
// @lc code=end

