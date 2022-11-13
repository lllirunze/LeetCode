/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool flag;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, word, 0, i, j);
                if(flag) {
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, string word, int curr, int x, int y) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[curr]) {
            return;
        }
        
        if(curr >= word.size() - 1) {
            flag = true;
            return;
        }
        
        char tmp = board[x][y];
        board[x][y] = '#';
        dfs(board, word, curr + 1, x + 1, y);
        dfs(board, word, curr + 1, x - 1, y);
        dfs(board, word, curr + 1, x, y - 1);
        dfs(board, word, curr + 1, x, y + 1);
        board[x][y] = tmp;
    }
};
// @lc code=end

