/*
 * @Author: Li Runze lirunze.me@gmail.com
 * @Date: 2022-10-26 20:18:51
 * @LastEditors: Li Runze lirunze.me@gmail.com
 * @LastEditTime: 2022-10-26 20:37:52
 * @FilePath: \LeetCode\2201.统计可以提取的工件.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=2201 lang=cpp
 *
 * [2201] 统计可以提取的工件
 */

// @lc code=start
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans = 0;
        int grid[1001][1001] = {0};
        for(int i=0; i<dig.size(); i++){
            grid[dig[i][0]][dig[i][1]] = 1;
        }
        for(int i=0; i<artifacts.size(); i++){
            bool check = true;
            for(int j=artifacts[i][0]; j<=artifacts[i][2]; j++){
                for(int k=artifacts[i][1]; k<=artifacts[i][3]; k++){
                    if(grid[j][k] == 0) check = false;
                }
            }
            if(check) ans++;
        }
        return ans;
    }
};
// @lc code=end

