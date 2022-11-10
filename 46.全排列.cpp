/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++){
            used.push_back(false);
        }
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums){
        if(tmp.size() == n){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i] == false){
                //这个可以加入
                tmp.push_back(nums[i]);
                used[i] = true;
                dfs(nums);
                tmp.pop_back();
                used[i] = false;
            }
            else continue;
        }
        return;
    }
};
// @lc code=end

