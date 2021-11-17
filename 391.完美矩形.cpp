/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 *
 * https://leetcode-cn.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (36.07%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 27.3K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
 * 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
 * 
 * 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * 输出：true
 * 解释：5 个矩形一起可以精确地覆盖一个矩形区域。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * 输出：false
 * 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
 * 
 * 示例 3：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
 * 输出：false
 * 解释：图形顶端留有空缺，无法覆盖成一个矩形。
 * 
 * 示例 4：
 * 
 * 
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * 输出：false
 * 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        map<pair<int,int>,int> m;
        //完美矩形特点1：各个面积之合等于最左小角与最右上角的乘积
        //完美矩形特点2：最左上，左下，右上，右下的点只出现一次
        //完美矩形特点3：其他点出现次数大于1
        //先计算所有面积
        int w,h;
        int size=rectangles.size();
        int s=0;
        for(int i=0;i<size;i++)
        {
            w=rectangles[i][2]-rectangles[i][0];
            h=rectangles[i][3]-rectangles[i][1];
            s+=w*h;
        }
        //找到最左下角的点
        int left_low1=INT_MAX;
        int left_low2=INT_MAX;
        for(int i=0;i<size;i++)
        {
            if(rectangles[i][0]<=left_low1&&rectangles[i][1]<=left_low2)
            {
                left_low1=rectangles[i][0];
                left_low2=rectangles[i][1];
            }
        }
        //找到最左上角的点
        int left_high1=INT_MAX;
        int left_high2=INT_MIN;
        for(int i=0;i<size;i++)
        {
            if(rectangles[i][0]<=left_high1&&rectangles[i][3]>=left_high2)
            {
                left_high1=rectangles[i][0];
                left_high2=rectangles[i][3];
            }
        }
        //找到最右上角的点
        int right_high1=INT_MIN;
        int right_high2=INT_MIN;
        for(int i=0;i<size;i++)
        {
            if(rectangles[i][2]>=right_high1&&rectangles[i][3]>=right_high2)
            {
                right_high1=rectangles[i][2];
                right_high2=rectangles[i][3];
            }
        }
        //找到最右下角的点
        int right_low1=INT_MIN;
        int right_low2=INT_MAX;
        for(int i=0;i<size;i++)
        {
            if(rectangles[i][2]>=right_low1&&rectangles[i][1]<=right_low2)
            {
                right_low1=rectangles[i][2];
                right_low2=rectangles[i][1];
            }
        }
        //判断出现次数 左下01左上03右下21右上23
        for(int i=0;i<size;i++)
        {
            m[make_pair(rectangles[i][0],rectangles[i][1])]++;
            m[make_pair(rectangles[i][0],rectangles[i][3])]++;
            m[make_pair(rectangles[i][2],rectangles[i][1])]++;
            m[make_pair(rectangles[i][2],rectangles[i][3])]++;
        }
        for(int i=0;i<size;i++)
        {
            if(rectangles[i][0]==left_low1&&rectangles[i][1]==left_low2&&m.count(make_pair(left_low1,left_low2))!=1)
                return false;
            if((rectangles[i][0]!=left_low1||rectangles[i][1]!=left_low2)&&m[make_pair(rectangles[i][0],rectangles[i][1])]%2)
            {
                return false;
            }
            if(rectangles[i][0]==left_high1&&rectangles[i][3]==left_high2&&m.count(make_pair(left_high1,left_high2))!=1)
                return false;
            if((rectangles[i][0]!=left_high1||rectangles[i][3]!=left_high2)&&m[make_pair(rectangles[i][0],rectangles[i][3])]%2)
            {
                return false;
            }
            if(rectangles[i][2]==right_low1&&rectangles[i][1]==right_low2&&m.count(make_pair(right_low1,right_low2))!=1)
                return false;
            if((rectangles[i][2]!=right_low1||rectangles[i][1]!=right_low2)&&m[make_pair(rectangles[i][2],rectangles[i][1])]%2)
            {
                return false;
            }
            if(rectangles[i][2]==right_high1&&rectangles[i][3]==right_high2&&m.count(make_pair(right_high1,right_high2))!=1)
                return false;
            if((rectangles[i][2]!=right_high1||rectangles[i][3]!=right_high2)&&m[make_pair(rectangles[i][2],rectangles[i][3])]%2)
            {
                return false;
            }
        }
        //判断
        if((right_high1-left_low1)*(right_high2-left_low2)==s&&left_high1==left_low1
        &&right_high1==right_low1&&left_high2==right_high2&&left_low2==right_low2)
            return true;
        else
            return false;
    }
};
// @lc code=end

