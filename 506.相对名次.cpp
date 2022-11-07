/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order;
        for(int i=0;i<nums.size();i++)
            order.push_back(i);
        sort(order.begin(),order.end(),[&nums](const int& a,const int& b){return nums[a]>nums[b];});
        vector<string> res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            switch(i)
            {
                case 0:res[order[i]]="Gold Medal";break;
                case 1:res[order[i]]="Silver Medal";break;
                case 2:res[order[i]]="Bronze Medal";break;
                default:res[order[i]]=to_string(i+1);break;
            }
        }
        return res;
    }
};
// @lc code=end

