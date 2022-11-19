/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> M;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            M[key].push_back(strs[i]);
        }
        for(auto ite=M.begin();ite!=M.end();ite++)
            res.push_back(ite->second);
        return res;
    }
};
// @lc code=end

