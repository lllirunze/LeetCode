/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 *
 * https://leetcode-cn.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (56.32%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    46.3K
 * Total Submissions: 81.2K
 * Testcase Example:  '"USA"'
 *
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如 "USA" 。
 * 单词中所有字母都不是大写，比如 "leetcode" 。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
 * 
 * 
 * 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word = "USA"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word = "FlaG"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= word.length <= 100
 * word 由小写和大写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int big=0;
        int small=0;
        int flag=0;
        for(int i=0;i<word.size();i++)
        {
            //判断首字母是否大写
            if(word[0]<'a'&&flag==0)
            {
                flag=1;
                continue;
            }
            if(word[0]>'Z'&&flag==0)
            {
                flag=2;
                continue;
            }
            if(word[i]>'Z')
                small++;
            if(word[i]<'a')
                big++;
        }
        if(flag==2&&small==word.size()-1)
            return true;
        if(flag==1&&small==word.size()-1)
            return true;
        if(flag==1&&big==word.size()-1)
            return true;
        return false;
    }
};
// @lc code=end

