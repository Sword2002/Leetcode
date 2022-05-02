/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.81%)
 * Likes:    412
 * Dislikes: 0
 * Total Accepted:    96.9K
 * Total Submissions: 220.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
int myabs(int a)
{
    return (a > 0 ? a : (0-a));
}

int comp(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

# if 0
int threeSumClosest(int* nums, int numsSize, int target){
    int sum = 0, i = 0;
    if (3 >= numsSize) {
        for (i = 0; i < numsSize; i++) {
            sum += nums[i];
        }
        return sum;
    }

    int l = 0, r = 0, min = 0, sumtemp = 0, abs = 0;
    qsort(nums, numsSize, sizeof(int), &comp);  // 排序

    sum = nums[0] + nums[1] + nums[2];         // 三数之和最小值
    min = myabs(sum - target);
    i = 0;
    while (i < (numsSize - 2))
    {
        sumtemp = nums[i] + nums[i+1] + nums[i+2];
        if (sumtemp > target) { // 已排序，往后和越大
            abs = myabs(sumtemp - target);
            if (abs < min) // 更接近
            {
                return sumtemp;
            }
            break;
        }
        l = i + 1;
        r = (numsSize - 1);
        while (l < r) // 双指针，左右夹击
        {
            sumtemp = nums[i] + nums[l] + nums[r];
            abs = myabs(sumtemp - target);
            if (sumtemp < target) {
                while (l < r && nums[l] == nums[++l]){}  // 去重复
            } else if (sumtemp > target) {
                while (l < r && nums[r] == nums[--r]){}  // 去重复
            } else {
                return sumtemp;
            }

            if (abs < min)
            {
                min = abs;
                sum = sumtemp;
            }
        }
        i++;
        //while ( i < (numsSize - 2) && nums[i] == nums[++i]){} // 去重复
    }
    return sum;
}
#endif
int threeSumClosest(int* nums, int numsSize, int target){
    int sum = 0, i = 0;
    if (3 >= numsSize) {
        for (i = 0; i < numsSize; i++) {
            sum += nums[i];
        }
        return sum;
    }

    int l = 0, r = 0, min = 0, sumtemp = 0, abs = 0;
    qsort(nums, numsSize, sizeof(int), &comp);  // 排序
    sum = nums[0] + nums[1] + nums[2];
    min = myabs(sum - target);

    for (i = 0; i < numsSize - 2; i++) {
        l = i + 1;
        r = numsSize - 1;

        while (l < r) {
            sumtemp = nums[i] + nums[l] + nums[r];
            abs = myabs(sumtemp - target);
            
            if (min > abs) {
                min = abs;
                sum = sumtemp;
            }

            if (sumtemp < target) {
                l++;
            } else if (sumtemp > target) {
                r--;
            } else {
                return sum;
            }
        }
    }

    return sum;
}
// @lc code=end

