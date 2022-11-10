/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[left]){
                //左半边升序，右半边无序
                if(target >= nums[left] && target <= nums[mid]){
                    //在左边
                    right = mid;
                }
                else{
                    //在右边
                    left = mid+1;
                }
            }
            else{
                //左半边无序，右半边有序
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid+1;
                }
                else right = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

