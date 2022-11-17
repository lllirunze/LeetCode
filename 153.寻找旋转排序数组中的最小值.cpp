/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int min;
        if(right == 0) return nums[0];
        
        while(left < right){
            if(nums[right] > nums[left]){
                // 此时已经是正常的升序数组
                return nums[left];
            }
            min = (left+right)/2;
            if(nums[min] > nums[min+1]){
                // 直接就找到了
                return nums[min+1];
            }
            if(nums[min] >= nums[left]){
                // 左边是正常的升序数组，看右边
                left = min+1;
            }
            else{
                // 右边是正常的升序数组，看左边
                right = min;
            }
        }
        return nums[left];
    }
};
// @lc code=end

