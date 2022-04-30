/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.32%)
 * Likes:    2464
 * Dislikes: 0
 * Total Accepted:    177.6K
 * Total Submissions: 475.9K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (0 == nums1Size) {
        if (nums2Size%2) {
            return (nums2[nums2Size/2]);
        } else {
            return ((nums2[nums2Size/2] + nums2[nums2Size/2 - 1])/2.0);
        }        
    }
    if (0 == nums2Size) {
        if (nums1Size%2) {
            return (nums1[nums1Size/2]);
        } else {
            return ((nums1[nums1Size/2] + nums1[nums1Size/2 - 1])/2.0);
        }        
    }

    int pos = (nums1Size + nums2Size);
    int flag = pos%2;  // 奇数，偶数
    pos /= 2;

    int num1 = 0, num2 = 0, i = 0, j = 0, k = 0;
    num2 = nums1[0] <= nums2[0] ? nums1[0] : nums2[0];



    for (i = 0; i <= pos; i++)
    {
        num2 = num1;
        if((k >= nums2Size) || ((j < nums1Size) && (nums1[j] <= nums2[k])))
        {
            num1 = nums1[j];
            if(j <= (nums1Size-1)) {
                j++;
            };
        } else {
            num1 = nums2[k];
            if(k <= (nums2Size-1)) {
                k++;
            };
        }
    }
    //printf("%d  %d\n", j, k);
    //printf("%d  %d\n", num1, num2);
    
    if (0 == flag) {
        return ((num1+num2)/2.0);
    } else {
        return (num1);
    }
}


// @lc code=end

