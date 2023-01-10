/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(int i=0; i<columnTitle.length(); i++){
            res = res*26 + (int)(columnTitle[i] - 'A' + 1);
        }
        return res;
    }
};
// @lc code=end

