/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 *
 * https://leetcode-cn.com/problems/heaters/description/
 *
 * algorithms
 * Medium (33.62%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    30K
 * Total Submissions: 82.3K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 * 
 * 在加热器的加热半径范围内的每个房屋都可以获得供暖。
 * 
 * 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
 * 
 * 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: houses = [1,2,3], heaters = [2]
 * 输出: 1
 * 解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: houses = [1,2,3,4], heaters = [1,4]
 * 输出: 1
 * 解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：houses = [1,5], heaters = [2]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 先排序
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0;
        int r = 1000000000;
        while (l<r) {
            // 二分查找
            int mid = l+(r-l)/2;
            if(check(houses, heaters, mid)) r = mid;
            else l = mid+1;
        }
        return r;
    }
    bool check(vector<int>& houses, vector<int>& heaters, int mid){
        // 检查加热半径是否覆盖所有房屋，若加热半径小于answer（无法全部覆盖，即不满足要求）则返回false，大于等于answer即满足要求返回true
        int n = houses.size();
        int m = heaters.size();
        for (int i=0,j=0; i<n; i++) {
            // 双指针
            while (j<m && houses[i]>heaters[j]+mid) {
                j++;
            }
            if(j<m && heaters[j]-mid<=houses[i] && houses[i]<=heaters[j]+mid) continue;
            else return false;
        }
        return true;
    }
};
// @lc code=end

