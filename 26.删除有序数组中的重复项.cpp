/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int left = 0, right = 1;
        while(right < n){
            if(nums[left] == nums[right]) right++;
            else{
                nums[left+1] = nums[right];
                left++;
                right++;
            }
        }
        return left+1;
    }
};
// @lc code=end

