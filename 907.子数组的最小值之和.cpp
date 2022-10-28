/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        // 单调栈：求上一个更小元素
        stack<int> stk;
        // dp[i] 表示以 i 结尾的子数组的最小值之和
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop(); 
            }    
            // 上一个更小元素
            int preIdx = stk.empty() ? -1 : stk.top();
            stk.push(i);
            
            if (preIdx == -1) {
                // 如果没有上一个更小元素，则以 i 结尾的 i + 1 个区间的最小值都为 arr[i]
                dp[i] = arr[i] * (i + 1); 
            } else {
                // 如果存在上一个更小元素，则 [preIdx, i] 之间的所有子区间的最小值都为 arr[i]
                dp[i] = dp[preIdx] + arr[i] * (i - preIdx);
            }
        }
        int res = 0;
        for (int cnt : dp) {
            res = (res + cnt) % MOD;
        }
        return res;
    }
};
// @lc code=end

