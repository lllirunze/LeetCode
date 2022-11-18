/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int cal(int a, int b) {
        if (a < 0 && b <= 0) return 1 - a;
        else return b - a;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        if (dungeon[m-1][n-1] >= 0) dp[m-1][n-1] = 1;
        else dp[m-1][n-1] = 1 - dungeon[m-1][n-1];
        for (int i = m - 2; i >= 0; --i)
            dp[i][n-1] = cal(dungeon[i][n-1], dp[i+1][n-1]);
        for (int i = n - 2; i >= 0; --i)
            dp[m-1][i] = cal(dungeon[m-1][i], dp[m-1][i+1]);
        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                dp[i][j] = min(cal(dungeon[i][j], dp[i+1][j]), cal(dungeon[i][j], dp[i][j+1]));
        return dp[0][0] > 0 ? dp[0][0] : 1;
    }
};
// @lc code=end

