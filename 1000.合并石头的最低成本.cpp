/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 *
 * https://leetcode-cn.com/problems/minimum-cost-to-merge-stones/description/
 *
 * algorithms
 * Hard (41.15%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 9.4K
 * Testcase Example:  '[3,2,4,1]\n2'
 *
 * 有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。
 * 
 * 每次移动（move）需要将连续的 K 堆石头合并为一堆，而这个移动的成本为这 K 堆石头的总数。
 * 
 * 找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：stones = [3,2,4,1], K = 2
 * 输出：20
 * 解释：
 * 从 [3, 2, 4, 1] 开始。
 * 合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
 * 合并 [4, 1]，成本为 5，剩下 [5, 5]。
 * 合并 [5, 5]，成本为 10，剩下 [10]。
 * 总成本 20，这是可能的最小值。
 * 
 * 
 * 示例 2：
 * 
 * 输入：stones = [3,2,4,1], K = 3
 * 输出：-1
 * 解释：任何合并操作后，都会剩下 2 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
 * 
 * 
 * 示例 3：
 * 
 * 输入：stones = [3,5,1,2,6], K = 3
 * 输出：25
 * 解释：
 * 从 [3, 5, 1, 2, 6] 开始。
 * 合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
 * 合并 [3, 8, 6]，成本为 17，剩下 [17]。
 * 总成本 25，这是可能的最小值。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= stones.length <= 30
 * 2 <= K <= 30
 * 1 <= stones[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int len=stones.size();
        //本来就是一堆的话,没有合并成本
        if(len < 2)
            return 0;
        //无论用什么方式,石头每次减少K-1个,但最终要剩K个石头
        if(len<K || (len-K)%(K-1)!=0)
            return -1;
        //sum[index]表示stones[0]加至stones[index]的总和(PS:sum[0]设为0)
        //动态方程:dp[left][right][heap]表示将编号left到right的石头合为heap堆的成本
        int sum[32]={0},dp[32][32][32];
        memset(dp,0x3f,sizeof(dp));
        for(int index=1;index<=len;index++){
            sum[index] = sum[index-1]+stones[index-1];
            //每个石子自成一堆,没有合并成本
            dp[index][index][1] = 0;
        }
            
        int span,left,right,mid,heap;
        //问题由小递推至大,因此先两个两个石头考虑,再三个三个石头考虑,通过span控制left与right的间距,从而递增考虑石子的个数
        for(span=1;span<len;span++){
            for(left=1;left<=len-span;left++){
                right=left+span;
                //决定在哪将要考虑的石子分为两部分
                for(mid=left;mid<right;mid++){
                    //先考虑分为两堆,三堆,仍然是递增考虑,堆数不可能超过石子数
                    for(heap=2;heap<=span+1;heap++){
                        //将本次考虑的所有石子合并为heap堆的成本,就是左部分是heap-1堆而右部分1堆相加的成本,反复更新dp[left][right][heap]以获取最小值
                        dp[left][right][heap] = min(dp[left][right][heap],dp[left][mid][heap-1]+dp[mid+1][right][1]);
                    }
                }
                //将本次考虑的所有石子合并为一堆的代价,就是将K堆石子合并起来的代价,反复更新dp[left][right][1]以获取最小值
                dp[left][right][1] = min(dp[left][right][1],dp[left][right][K]+sum[right]-sum[left-1]);
            }
        }
        //将编号为1到len的石子合成一堆的成本即最终答案
        return dp[1][len][1];   
    }
};
// @lc code=end

