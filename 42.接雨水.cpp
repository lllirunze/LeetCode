/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int maxheight = 0;
        int maxitem = 0;
        int n = height.size();
        // 确定最高位置
        for(int i=0; i<n; i++){
            if(height[i]>maxheight){
                maxheight = height[i];
                maxitem = i;
            }
        }
        int ans = 0;
        // 接左边的雨水
        int leftitem = 0;
        for(int i=1; i<maxitem; i++){
            if(height[i]<height[leftitem]){
                ans += (height[leftitem]-height[i]);
            }
            else leftitem = i;
        }
        // 接右边的雨水
        int rightitem = n-1;
        for(int i=n-2; i>maxitem; i--){
            if(height[i]<height[rightitem]){
                ans += (height[rightitem]-height[i]);
            }
            else rightitem = i;
        }
        return ans;
    }
};
// @lc code=end

