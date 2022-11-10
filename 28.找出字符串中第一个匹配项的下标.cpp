/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int len = needle.length();
        int res = -1;
        for(int i=0; i<n-len+1; i++){
            bool check = true;
            for(int j=0; j<len; j++){
                if(haystack[i+j] != needle[j]){
                    check = false;
                    break;
                }
            }
            if(check){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

