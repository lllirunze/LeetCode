/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i < n; i++)
        {
            matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1]);
            matrix[i][n - 1] += min(matrix[i - 1][n - 2], matrix[i - 1][n - 1]);
            for(int j = 1; j < n - 1; j++)
                matrix[i][j] += min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i - 1][j + 1])); 
        }
        int tmp = INT_MAX;
        for(int j = 0; j < n; j++)
            tmp = min(tmp, matrix[n - 1][j]);
        return tmp;
    }
};
// @lc code=end

