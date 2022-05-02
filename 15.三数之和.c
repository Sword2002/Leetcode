/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.60%)
 * Likes:    2046
 * Dislikes: 0
 * Total Accepted:    207.9K
 * Total Submissions: 779K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <stdlib.h>

int mycmp(int *a, int *b)
{
    return (*a - *b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (numsSize < 3)
    {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), &mycmp); // 排序：升序

    int **res = (int **)malloc(sizeof(int *) * 6 * numsSize); // 
    *returnColumnSizes = malloc(sizeof(int) * 6 * numsSize);
    
    int i = 0, j = 0, k = 0, r = 0;
    while (i < (numsSize - 2))
    {
        if (nums[i] > 0) {break;} // 已经过排序
        if ((nums[i] + nums[i+1] + nums[i+2]) > 0) {break;} // 已经过排序

        j = i + 1;         // 左位置
        k = numsSize - 1;  // 右位置
        while (j < k)
        {
            if ((nums[i] + nums[j] + nums[k]) < 0) {
                j++;
            } else if ((nums[i] + nums[j] + nums[k]) > 0) {
                k--;
            } else {
                res[r] = malloc(sizeof(int) * 3);
                res[r][0] = nums[i];
                res[r][1] = nums[j];
                res[r][2] = nums[k];
                (*returnColumnSizes)[r++] = 3;

                while(nums[j] == nums[++j] && j < k) {} // 去重复
                while(nums[k] == nums[--k] && j < k) {} // 去重复
            }
        }
        while(nums[i] == nums[++i] && i < (numsSize - 2)) {} // 去重复
    }

    *returnSize = r;
    return ((int **)res);
}


// @lc code=end

