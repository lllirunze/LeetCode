/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int hashmap[130];
    int lengthOfLongestSubstring(string s) { //双指针滑动窗口
        int max=0;
        int n = s.size();
        for(int i=0,j=0;j<n;j++){//当前判断是否重复的串为s[i..j]
            hashmap[s[j]]++;
            while(hashmap[s[j]]>1){
                hashmap[s[i++]]--;  //i指针右移
            }
            if(j-i+1>max)
                max = j-i+1;
        }
        return max;
    }
};
// @lc code=end

