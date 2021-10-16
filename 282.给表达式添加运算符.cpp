/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 *
 * https://leetcode-cn.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (45.85%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 30.9K
 * Testcase Example:  '"123"\n6'
 *
 * 给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 *
 * ，返回所有能够得到目标值的表达式。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num = "123", target = 6
 * 输出: ["1+2+3", "1*2*3"] 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: num = "232", target = 8
 * 输出: ["2*3+2", "2+3*2"]
 * 
 * 示例 3:
 * 
 * 
 * 输入: num = "105", target = 5
 * 输出: ["1*0+5","10-5"]
 * 
 * 示例 4:
 * 
 * 
 * 输入: num = "00", target = 0
 * 输出: ["0+0", "0-0", "0*0"]
 * 
 * 
 * 示例 5:
 * 
 * 
 * 输入: num = "3456237490", target = 9191
 * 输出: []
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 10
 * num 仅含数字
 * -2^31 <= target <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
    
public:
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        function<void(string,long,long,int)>dfs=[&](string s,long lastEval,long lastNumber,int start){
            if(start==num.size()){
                if(lastEval==target)ans.push_back(s);
                return;
            }
            long currentEval=0l;
            for(int end=start;end<num.size();end++){
                string ss=num.substr(start,end-start+1);
                currentEval=currentEval*10+(num[end]-'0');
                if(start==0)
                    dfs(ss,currentEval,currentEval,end+1);
                else{
                    dfs(s+"*"+ss,lastEval+(currentEval-1)*lastNumber,lastNumber*currentEval,end+1);
                    dfs(s+"+"+ss,lastEval+currentEval,currentEval,end+1);
                    dfs(s+"-"+ss,lastEval-currentEval,-currentEval,end+1);
                }
                if(currentEval==0)return;
            }
        };
        dfs("",0,0,0);
        return ans;
    }
    
};
// @lc code=end

