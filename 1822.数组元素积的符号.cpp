/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0) ans = -ans;
        }
        return ans;
    }
};
// @lc code=end

