/*
 * @Author: Li Runze lirunze.me@gmail.com
 * @Date: 2022-10-24 21:38:20
 * @LastEditors: Li Runze lirunze.me@gmail.com
 * @LastEditTime: 2022-10-24 22:48:12
 * @FilePath: \undefinedd:\Lirz3\Desktop\源程序\LeetCode\1284.转化为全零矩阵的最少反转次数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=1284 lang=cpp
 *
 * [1284] 转化为全零矩阵的最少反转次数
 */

// @lc code=start
class Solution {
public:
    void turn(vector<vector<int>> &mat,int x,int y)
    {
        int n = mat.size(),m = mat[0].size();
        int dx[5] = {0,1,0,-1,0},dy[5] = {0,0,1,0,-1};
        for (int i = 0;i < 5;i ++)
        {
            int a = x + dx[i],b = y + dy[i];
            if(a < 0 || b < 0 || a >= n || b >= m) continue;
            mat[a][b] ^= 1;
        }
    }
    int work(vector<vector<int>> &mat)
    {
        vector<vector<int>> temp = mat;
        int n = mat.size(),m = mat[0].size();
        int ans = 1e8;

        for (int i = 0;i < 1 << m;i ++)
        {
            int res = 0;

            for (int j = 0;j < m;j ++)
            if(i >> j & 1)
            {
                res ++;
                turn(mat,0,j);
            }

            for (int k = 0;k < n - 1;k ++)
                for (int j = 0;j < m;j ++)
                if(mat[k][j] == 1)
                {
                    res ++;
                    turn(mat,k + 1,j);
                }
            
            bool is_allzero = true;
            for (int j = 0;j < m;j ++)
            if(mat[n - 1][j] == 1)
            {
                is_allzero = false;
                break;
            }

            if(is_allzero) ans = min(ans,res);
            mat = temp;
        }
        
        if(ans == 1e8) return -1;
        return ans;
    }
    int minFlips(vector<vector<int>>& mat) {
        return work(mat);
    }
};
// @lc code=end

