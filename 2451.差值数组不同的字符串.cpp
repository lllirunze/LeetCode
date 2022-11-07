/*
 * @lc app=leetcode.cn id=2451 lang=cpp
 *
 * [2451] 差值数组不同的字符串
 */

// @lc code=start
class Solution {
public:
    char change(char c, int bias){
        if(c-bias >= 'a') return c-bias;
        else return c+26-bias;
    }

    string oddString(vector<string>& words) {
        vector<string> word;
        int n = words.size();
        for(int i=0; i<n; i++){
            word.push_back(words[i]);
        }
        int len = words[0].length();
        int bias;
        for(int i=0; i<n; i++){
            bias = word[i][0]-'a';
            for(int j=0; j<len; j++){
                word[i][j] = change(word[i][j], bias);
            }
        }
        int res;
        if(word[0] == word[1]){
            string stdString = word[0];
            for(int i=2; i<n; i++){
                if(word[i] != stdString){
                    res = i;
                    break;
                }
            }
        }
        else{
            if(word[0] == word[2]) res = 1;
            else res = 0;
        }
        return words[res];
    }
};
// @lc code=end

