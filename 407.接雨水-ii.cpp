/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 *
 * https://leetcode-cn.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (53.12%)
 * Likes:    449
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 28.3K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * 给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
 * 输出: 4
 * 解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: heightMap =
 * [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
 * 输出: 10
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * m == heightMap.length
 * n == heightMap[i].length
 * 1 <= m, n <= 200
 * 0 <= heightMap[i][j] <= 2 * 10^4
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    int move[4][2] {-1, 0, 0, -1, 0, 1, 1, 0};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        int maxHeight = 0;
        //假设初始不漏水，蓄水后全部达到最大高度，然后bfs依次漏水
        for(vector<int> &nums : heightMap)
            for(int &num : nums)
                maxHeight = max(maxHeight, num);
        vector<vector<int>> water(m, vector<int>(n, maxHeight));
        queue<pair<int, int>> q;
        //四周不可能蓄水，改变water值, 并作为bfs起点入栈
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                    //此时墙壁最高，不可能漏水，跳过
                    if(water[i][j] == heightMap[i][j])
                        continue;
                    water[i][j] = heightMap[i][j];
                    q.push(make_pair(i, j));
                }
            }
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + move[i][0], ny = y + move[i][1];
                //边界判断，四周即停止
                if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                //如果此时可以漏水，即邻近点的水位要比当前的水位还要高，开始漏水
                if(water[x][y] < water[nx][ny] && heightMap[nx][ny] < water[nx][ny]){ 
                    //更新，进行剪枝，只有在水高比自身高的情况写下才更新，毕竟漏水不可能把自己的高度漏没，原判断为if(water[x][y] < water[nx][ny]){
                    //蓄水后的高度为邻近水高于本身高度的较大值，即蓄水后高度一定不小于自身高度
                    water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
                    //bfs经典入栈
                    q.push(make_pair(nx, ny));
                }
            }
        }
        int ans = 0;
        //计算总蓄水量
         for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                ans += water[i][j] - heightMap[i][j];
        return ans;
    }
};
// @lc code=end

