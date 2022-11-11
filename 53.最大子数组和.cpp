/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int res = INT_MIN;
        int f_n = -1;
        for(int i = 0; i < nums.size(); ++i){
            f_n = max(nums[i], f_n + nums[i]);
            res = max(f_n, res);
        }
        return res;
    }
};
// @lc code=end

