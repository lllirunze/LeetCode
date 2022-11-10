/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++){
            used.push_back(false);
        }
        dfs(nums);
        return res;
    }
    bool judge(vector<vector<int>>& res, vector<int>& tmp){
        int m = res.size();
        bool jud;
        for(int i=0; i<m; i++){
            jud = true;
            for(int j=0; j<n; j++){
                if(res[i][j] != tmp[j]){
                    jud = false;
                    break;
                }
            }
            if(jud) return false;
        }
        return true;
    }
    void dfs(vector<int>& nums){
        if(tmp.size() == n){
            if(judge(res, tmp)){
                res.push_back(tmp);
            }
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

