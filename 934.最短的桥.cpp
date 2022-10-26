/*
 * @Author: Li Runze lirunze.me@gmail.com
 * @Date: 2022-10-25 16:25:46
 * @LastEditors: Li Runze lirunze.me@gmail.com
 * @LastEditTime: 2022-10-25 23:17:46
 * @FilePath: \LeetCode\934.最短的桥.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // dfs 将所有源节点入队列
                    dfs(grid, i, j);
                    // bfs 搜索最短路径
                    return bfs(grid);
                }
            }
        }
        return 0;
    }

private:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= m) {
            return;
        } 
        if (grid[i][j] != 1) {
            return;
        }
        // 访问过的节点设为 -1，防止再次访问
        grid[i][j] = -1;
        q.push({i, j});
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    int bfs(vector<vector<int>> &grid) {
        int res = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for (int k = 0; k < qSize; k++) {
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for (int r = 0; r < 4; r++) {
                    int nx = x + dx[r], ny = y + dy[r]; 
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                        continue;
                    }
                    if (grid[nx][ny] == -1) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        return res;
                    } 
                    grid[nx][ny] = -1;
                    q.push({nx, ny});
                }        
            }
            res++;
        }
        return res;
    }
};
// @lc code=end

