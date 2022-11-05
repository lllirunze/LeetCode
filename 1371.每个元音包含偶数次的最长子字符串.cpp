/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m;

        int ans = 0, st = 0;

        m[0] = 0;
        for (int i = 0; i < s.size(); i ++ )
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||  s[i] == 'o' ||  s[i] == 'u')
            {
                st ^= 1 << (s[i] - 'a');
            }
            if (m.count(st))
                ans = max(ans, i + 1 - m[st]);
            else 
                m[st] = i + 1;
        }
        return ans;
    }
};
// @lc code=end

