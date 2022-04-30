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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void insertion_sort(int arr[], int len);
#if 1
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (numsSize < 3)
    {
        *returnSize = 0;
        return NULL;
    }

    insertion_sort(nums, numsSize); // 排序：升序
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
#else
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) {
        return 0;
    }
    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;
    int target = 0;
    
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);
    qsort(nums, numsSize, sizeof(int), comp);
    ret[*returnSize] = malloc(sizeof(int) * 3);

    while (left + 1 < right) {
        int i = left + 1;
        int j = right;
        target = 0 - nums[left];
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                i++;
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                ret[*returnSize][0] = nums[left];
                ret[*returnSize][1] = nums[i];
                ret[*returnSize][2] = nums[j];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                ret[*returnSize] = malloc(sizeof(int) * 3);

                while(nums[i] == nums[++i] && i < j) {}
                while(nums[j] == nums[--j] && i < j) {}
            }
        }
        while(nums[left] == nums[++left] && left + 1 < right) {}
    }
    
    return ret;
}
#endif
// 插入排序
void insertion_sort(int arr[], int len)
{
    int i,j,temp;
    for (i=1;i<len;i++)
    {
        temp = arr[i];
        for (j=i;j>0 && arr[j-1]>temp;j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}    

// @lc code=end

