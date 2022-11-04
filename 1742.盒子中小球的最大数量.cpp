/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int countBalls(int l, int h) {
        // 编号有5位，那么各位数字之和最大为5*9=45，那么盒子的编号最多为45位，我们开50就行了
        vector<int> sum(50,0);
        int res=-1;
        for(int i=l;i<=h;++i)
        {
            int x=i,s=0;
            // 计算各位数字之和
            while(x)s+=x%10,x/=10;
            sum[s]++;
            res=max(res,sum[s]);
        }
        return res;
    }
};
// @lc code=end

