/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.30%)
 * Likes:    963
 * Dislikes: 0
 * Total Accepted:    232.9K
 * Total Submissions: 341K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 30 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            res.push_back(0);
        }
        stack<int> s;
        s.push(0);
        for(int i=1; i<n; i++){
            while(!s.empty()){
                if(temperatures[i]>temperatures[s.top()]){
                    res[s.top()] = i-s.top();
                    s.pop();
                }
                else {
                    break;
                }
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end

