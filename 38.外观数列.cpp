/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (59.33%)
 * Likes:    807
 * Dislikes: 0
 * Total Accepted:    236.9K
 * Total Submissions: 399.3K
 * Testcase Example:  '1'
 *
 * 给定一个正整数 n ，输出外观数列的第 n 项。
 * 
 * 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
 * 
 * 你可以将其视作是由递归公式定义的数字字符串序列：
 * 
 * 
 * countAndSay(1) = "1"
 * countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
 * 
 * 
 * 前五项如下：
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 第一项是数字 1 
 * 描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
 * 描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
 * 描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
 * 描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
 * 
 * 
 * 要 描述 一个数字字符串，首先要将字符串分割为 最小 数量的组，每个组都由连续的最多 相同字符
 * 组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。
 * 
 * 例如，数字字符串 "3322251" 的描述如下图：
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 1
 * 输出："1"
 * 解释：这是一个基本样例。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 4
 * 输出："1211"
 * 解释：
 * countAndSay(1) = "1"
 * countAndSay(2) = 读 "1" = 一 个 1 = "11"
 * countAndSay(3) = 读 "11" = 二 个 1 = "21"
 * countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        // 迭代计算结果 初始化为1
        string ans = "1";

        // 只需要计算n-1次；如果n为1，可以直接返回ans
        for (int t = 1; t < n; t++) {
            char tmp = ans[0];
            int cnt = 0;
            // 新的字符串用来记录新的外观数列
            string new_ans = "";
            for (int i = 0; i < ans.size(); i++) {
                // 和前面的数字相同 计数器+1
                if (ans[i] == tmp) cnt++;
                else {
                    // 不同的时候，我们就应该把之前的计数和对应的数字拼接起来了
                    // count + number_string
                    new_ans += to_string(cnt) + tmp;
                    // 将新的数字和出现次数1记录 继续进行相同的迭代操作
                    tmp = ans[i];
                    cnt = 1;
                }
            }
            // 迭代完成时；tmp里还存有最后一组不同的数字；不要遗漏
            new_ans += to_string(cnt) + tmp;
            
            ans = new_ans;
        }

        return ans;
    }
};
// @lc code=end

