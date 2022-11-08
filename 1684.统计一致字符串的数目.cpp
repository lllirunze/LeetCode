/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(const string& allowed, vector<string>& words) {
        return count_if(words.cbegin(), words.cend(), [flg = accumulate(allowed.cbegin(), allowed.cend(), 0, [](int num, char ch) { return num | (1 << (ch - 'a')); })](auto&& s) { return all_of(s.cbegin(), s.cend(), [&](char ch) { return (flg >> (ch - 'a')) & 1; }); });
    }
};
// @lc code=end

