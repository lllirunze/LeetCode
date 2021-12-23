/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 *
 * https://leetcode-cn.com/problems/longest-duplicate-substring/description/
 *
 * algorithms
 * Hard (29.65%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 43.9K
 * Testcase Example:  '"banana"'
 *
 * 给你一个字符串 s ，考虑其所有 重复子串 ：即，s 的连续子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。
 * 
 * 返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "banana"
 * 输出："ana"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd"
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 3 * 10^4
 * s 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
# define ull unsigned long long
class Solution {
    vector<ull> f,p;
    unordered_map<ull, bool> mp;
    string ans = "";
    int n;
public:
    bool check(int m,string &s)
    {
        ull has=0;
        mp.clear();
        for(int i=1; i <= n - m;++i)
        {
            has=f[i+m]-f[i-1]*p[m+1];            
            if(mp[has])
            {
                if(ans.size()<m+1)ans=s.substr(i-1,m+1);
                return 1;
            }   
            mp[has]=1; 
        }
        return 0;
    }
    string longestDupSubstring(string s) {
        n=s.size();
        f.resize(n+1,0);
        p.resize(n+1,0);
        p[0]=1;
        for(int i=1;i<=n;++i)
        {
            f[i]=f[i-1]*131+(s[i-1]-'a'+1);
            p[i]=p[i-1]*131;
        }

        int l=0,r=n,m;
        while(l<r)
        {
            m=l+r>>1;
            if(check(m,s))l=m+1;
            else r=m;
        }
        return ans;
    }
};
// @lc code=end

