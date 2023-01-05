/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int n = columnNumber;
        while(n > 0){
            int current = (n-1) % 26;
            n = (n-1) / 26;
            char c;
            c = 'A'+current;
            res = c + res;
        }
        return res;
    }
};
// @lc code=end

