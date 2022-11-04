/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int step = 0;
        while (sum < target || (sum - target) % 2 != 0) {
            step++; 
            sum += step;
        }
        return step;
    }
};
// @lc code=end

