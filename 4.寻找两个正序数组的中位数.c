/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.28%)
 * Likes:    5357
 * Dislikes: 0
 * Total Accepted:    691.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int remain = (nums1Size + nums2Size) % 2;
    int mid = (nums1Size + nums2Size) / 2;
    int ret;
    int retlast = 0;

    int i, j, k;
    i = 0;
    j = 0;
    for (k = 0; k <= mid; k++) {
        if (remain == 0) {
            retlast = ret;
        }
 
        if (j < nums2Size && i < nums1Size) {
            if (nums1[i] <= nums2[j]) {
                ret = nums1[i];
                i++;
            } else {
                ret = nums2[j];
                j++;
            }
        } else if (i < nums1Size) {
            ret = nums1[i];
            i++;
        } else {
            ret = nums2[j];
            j++;
        }
    }

    if (remain == 0) {
        return (double)(ret + retlast) / 2.0;
    } else {
        return (double)ret;
    }
}
// @lc code=end

