/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (50.72%)
 * Likes:    1734
 * Dislikes: 0
 * Total Accepted:    155.3K
 * Total Submissions: 294.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start


int trap(int* height, int heightSize){
    int i,j,leftmax,rightmax,secondmax,water=0;
    for(i=1;i<heightSize-2;i++)
    {
        leftmax=0;
        for(j=0;j<=i;j++)
        {
            leftmax > height[j] ? leftmax = leftmax : leftmax = height[j];
        }
       rightmax=0;
        for(j=j;j<heightSize;j++)
        {
            rightmax>height[j]?rightmax=rightmax:rightmax=height[j];
        }
        leftmax>rightmax?secondmax=leftmax:secondmax=rightmax;
        water +=  secondmax-height[i];
    }

    return water;
}


// @lc code=end

