/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool valid(char c){
        if((c>='A'&&c<='Z') || (c>='a'&& c<='z') || (c>='0'&&c<='9')) return true;
        else return false;
    }
    bool check(char a, char b){
        if(a>='A' && a<='Z') a = a+('a'-'A');
        if(b>='A' && b<='Z') b = b+('a'-'A');
        if(a == b) return true;
        else return false;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left < right){
            if(!valid(s[left])){
                left++;
                continue;
            }
            if(!valid(s[right])){
                right--;
                continue;
            }
            if(check(s[left], s[right])){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

