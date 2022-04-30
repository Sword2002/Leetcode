/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.48%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 199K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start

void insertion_sort(int arr[], int len);
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    if (3 >= numsSize) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), comp); // 排序

    int **res = (int **)malloc(sizeof(int *) * (numsSize + 1) * 24);
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 24);

    int i = 0, j = 0, l = 0, r = 0, index = 0;
    while (i < (numsSize - 3))
    {
        if ((nums[i] + nums[i+1] + nums[i+2]  + nums[i+3]) > target) {break;} // 已经过排序
        j = i + 1;
        while (j < (numsSize - 2))
        {
            if ((nums[i] + nums[j] + nums[j+1]  + nums[j+2]) > target) {break;} // 已经过排序
            l = j + 1;
            r = numsSize - 1;
            while (l < r)
            {
                if ((nums[i] + nums[j] + nums[l]  + nums[r]) > target) {
                    r--;
                } else if ((nums[i] + nums[j] + nums[l]  + nums[r]) < target) {
                    l++;
                } else {
                    res[index] = malloc(sizeof(int) * 4);
                    res[index][0] = nums[i];
                    res[index][1] = nums[j];
                    res[index][2] = nums[l];
                    res[index][3] = nums[r];
                    (*returnColumnSizes)[index++] = 4;
                    while (nums[l] == nums[++l] && l < r) {}
                    while (nums[r] == nums[--r] && l < r) {}
                }
            }
            while (nums[j] == nums[++j] && j < (numsSize - 2)) {}
        }
        while (nums[i] == nums[++i] && i < (numsSize - 3)) {}
    }

    *returnSize = index;
    return res;
}

// @lc code=end

