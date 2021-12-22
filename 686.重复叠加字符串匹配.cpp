/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 *
 * https://leetcode-cn.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Medium (38.01%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 70.6K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * 给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。
 * 
 * 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：a = "abcd", b = "cdabcdab"
 * 输出：3
 * 解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：a = "a", b = "aa"
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：a = "a", b = "a"
 * 输出：1
 * 
 * 
 * 示例 4：
 * 
 * 输入：a = "abc", b = "wxyz"
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length <= 10^4
 * 1 <= b.length <= 10^4
 * a 和 b 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string tempa=a;
        int alen=a.length(), blen=b.length();
        int midlen=blen/alen;
        if(alen>=blen){
            string doublea=a+a;
            if(tempa.find(b) != string::npos){
                return 1;
            }
            else if(doublea.find(b) != string::npos){
                return 2;
            }
            else return -1;
        }
        else{
            for(int i=1; i<=midlen+2; i++){
                if(tempa.find(b) != string::npos){
                    return i;
                }
                tempa += a;
            }
            return -1;
        }
        return -1;
    }
};
// @lc code=end

