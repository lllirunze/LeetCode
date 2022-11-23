/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void del(vector<vector<char>>& grid, int i, int j, int row, int col){
        grid[i][j] = '0';
        if(i-1 >= 0){
            if(grid[i-1][j] == '1') del(grid, i-1, j, row, col);
        }
        if(i+1 <= row-1){
            if(grid[i+1][j] == '1') del(grid, i+1, j, row, col);
        }
        if(j-1 >= 0){
            if(grid[i][j-1] == '1') del(grid, i, j-1, row, col);
        }
        if(j+1 <= col-1){
            if(grid[i][j+1] == '1') del(grid, i, j+1, row, col);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    res++;
                    del(grid, i, j, row, col);
                }
            }
        }
        return res;
    }
};
// @lc code=end

