/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count[n];
        count[n-1] = 0;
        int min;
        for(int i=n-2; i>=0; i--){
            if(nums[i] == 0){
                count[i] = 100000;
                continue;
            }
            min = 100001;
            for(int j=i+1; j<=i+nums[i] && j<n; j++){
                if(count[j] < min){
                    min = count[j];
                }
            }
            count[i] = min+1;
        }
        return count[0];
    }
};
// @lc code=end

