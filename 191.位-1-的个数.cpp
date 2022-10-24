/*
 * @Author: Li Runze lirunze.me@gmail.com
 * @Date: 2022-10-23 21:52:21
 * @LastEditors: Li Runze lirunze.me@gmail.com
 * @LastEditTime: 2022-10-24 21:36:55
 * @FilePath: \undefinedd:\Lirz3\Desktop\源程序\LeetCode\191.位-1-的个数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            if(n<<31>>31 == 1) ans++;
            n = n>>1;
        }
        return ans;
    }
};
// @lc code=end

