/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.41%)
 * Likes:    1014
 * Dislikes: 0
 * Total Accepted:    310.2K
 * Total Submissions: 540K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start


bool isPalindrome(int x){
    if (x < 0) {
        return false;
    } else if (x < 10) {
        return true;
    }


    int large = 1e9;
    while (0 == x/large) // x >= 10
    {
        large /= 10;
    }

    int small = 10;
    int i, r;

    while (large >= small)
    {
        i = x / large;
        r = (x % small) / (small / 10);

        if (i != r) {
            return false;
        }

        x %= large;
        large /= 10;
        small *= 10;
    }
    return true;
}


// @lc code=end

