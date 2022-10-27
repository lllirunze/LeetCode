/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(j-i == 0) dp[i][j] = 1;
                else if(j-i == 1){
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else{
                    if(dp[i+1][j-1] == 0) dp[i][j] = 0;
                    else{
                        if(s[i] == s[j]) dp[i][j] = 1;
                        else dp[i][j] = 0;
                    }
                }
            }
        }
        int left = 0;
        int maxlength = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j] == 1 && (j-i+1)>maxlength){
                    left = i;
                    maxlength = j-i+1;
                }
            }
        }
        return s.substr(left, maxlength);
    }
};
// @lc code=end

