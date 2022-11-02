/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxq = 0, resx = 0, resy = 0;
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                int quality = 0;
                for (auto tower : towers) {
                    int x = tower[0], y = tower[1], q = tower[2];
                    int d2 = (x - i) * (x - i) + (y - j) * (y - j);
                    if (d2 <= radius * radius) {
                        quality += (int)(q / (1 + sqrt(d2)));   
                    }
                }
                // 因为我们是按照字典序遍历坐标的，所以第一个最大值一定是字典序最小的
                if (maxq < quality) {
                    maxq = quality;
                    resx = i;
                    resy = j;
                }
            }
        }
        return {resx, resy};
    }
};
// @lc code=end

