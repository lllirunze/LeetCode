/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp1;
        int tmp2;
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                tmp1 = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                tmp2 = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp2;
            }
        }
    }
};
// @lc code=end

