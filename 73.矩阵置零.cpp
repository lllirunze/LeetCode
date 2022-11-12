/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0; i<row.size(); i++){
            for(int j=0; j<n; j++){
                matrix[row[i]][j] = 0;
            }
        }
        for(int j=0; j<col.size(); j++){
            for(int i=0; i<m; i++){
                matrix[i][col[j]] = 0;
            }
        }
        return;
    }
};
// @lc code=end

