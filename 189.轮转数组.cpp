/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rot[n];
        for(int i=0; i<n; i++){
            rot[i] = nums[(i+n-(k%n))%n];
        }
        for(int i=0; i<n; i++){
            nums[i] = rot[i];
        }
        return;
    }
};
// @lc code=end

