/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;

        // 先判断边界情况
        if (nums[0] > nums[1]) return 0;
        if (nums[len - 1] > nums[len - 2]) return len - 1;

        int left = 0, right = len - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            // 当前是峰值
            if (mid >= 1 && mid < len - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (mid >= 1 && nums[mid] < nums[mid - 1])
            {
                // 峰值在左侧
                right = mid - 1;
            }
            else if (mid < len - 1 && nums[mid] < nums[mid + 1])
            {
                // 峰值在右侧
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

