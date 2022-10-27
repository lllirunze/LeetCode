/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int lmax1, lmax2, rmin1, rmin2, c1, c2, lo = 0, hi = n*2;

        while(lo<=hi){
            c1 = (lo+hi)/2;
            c2 = m+n-c1;
            lmax1 = (c1==0) ? INT_MIN : nums1[(c1-1)/2];
            rmin1 = (c1==n*2) ? INT_MAX : nums1[c1/2];
            lmax2 = (c2==0) ? INT_MIN : nums2[(c2-1)/2];
            rmin2 = (c2==m*2) ? INT_MAX : nums2[c2/2];

            if(lmax1 > rmin2) hi = c1-1;
            else if(lmax2 > rmin1) lo = c1+1;
            else break;
        }

        return (max(lmax1, lmax2) + min(rmin1, rmin2))/2.0;
    }
};
// @lc code=end

