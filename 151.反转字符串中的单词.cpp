/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stack<string> res;
        string str = "", ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' ' && str == ""){
                continue;
            }
            else if(s[i] == ' ' && str != ""){
                res.push(str);
                str = "";
            }
            else{
                str = str+s[i];
            }
        }
        if(s[s.length()-1] == ' '){
            ans = res.top();
            res.pop();
        }
        else{
            ans = str;
        }
        while(!res.empty()){
            ans = ans + " " + res.top();
            res.pop();
        }
        return ans;
    }
};
// @lc code=end

