/*
 * @lc app=leetcode.cn id=2443 lang=cpp
 *
 * [2443] 反转之后的数字和
 */

// @lc code=start
class Solution {
public:

    int reverse(int num){
        int re = 0;
        int n = num;
        while(n){
            re = re*10+(n%10);
            n = n/10;
        }
        return re;
    }

    bool sumOfNumberAndReverse(int num) {
        for(int i=0; i<=num; i++){
            if(i+reverse(i) == num) return true;
        }
        return false;
    }
};
// @lc code=end

