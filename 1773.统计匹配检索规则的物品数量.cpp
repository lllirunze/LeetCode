/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key;
        int ans = 0;
        if(ruleKey == "type") key = 0;
        else if(ruleKey == "color") key = 1;
        else if(ruleKey == "name") key = 2;
        int n = items.size();
        for(int i=0; i<n; i++){
            if(items[i][key] == ruleValue) ans++;
        }
        return ans;
    }
};
// @lc code=end

