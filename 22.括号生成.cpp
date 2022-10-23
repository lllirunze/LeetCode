/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.28%)
 * Likes:    2259
 * Dislikes: 0
 * Total Accepted:    400.1K
 * Total Submissions: 517.7K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func(res, "", 0, 0, n);
        return res;
    }
    
    void func(vector<string> &res, string str, int l, int r, int n){
        if(l > n || r > n || r > l) return ;
        if(l == n && r == n) {res.push_back(str); return;}
        func(res, str + '(', l+1, r, n);
        func(res, str + ')', l, r+1, n);
        return;
    }
};
// @lc code=end

