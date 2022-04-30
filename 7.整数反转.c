/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (35.21%)
 * Likes:    3497
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.8M
 * Testcase Example:  '123'
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 123
 * 输出：321
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = -123
 * 输出：-321
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 120
 * 输出：21
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：x = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * 
 * 
 */

// @lc code=start
#define INT_MAX_DIV10 214748364
#define INT_MAX_LAST 7
#define INT_MIN_DIV10 -214748364
#define INT_MIN_LAST -8

bool IsOverInt(int ret, int remain);

// [-2147483648, 2147483647]
int reverse(int x){
    int ret = 0;
    int i = 0;
    while (x != 0) {
        ret *= 10;
        ret += x % 10;
        x = x / 10;
        if (++i == 9) {
            if (IsOverInt(ret, x)) {
                return 0;
            }
        }
        // printf("ret = %d, x = %d\n", ret, x);
    }

    return ret;
}

// 判断整数是否会超出int 32位范围
// true : 超出范围
bool IsOverInt(int ret, int remain)
{
    if ((ret < INT_MIN_DIV10 && remain != 0) || 
        (ret == INT_MIN_DIV10 && remain < INT_MIN_LAST) ||
        (ret > INT_MAX_DIV10 && remain != 0) || 
        (ret == INT_MAX_DIV10 && remain > INT_MAX_LAST)) {
            return true;
    }

    return false;
}

// @lc code=end

