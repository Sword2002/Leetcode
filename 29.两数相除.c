/*
 * @lc app=leetcode.cn id=29 lang=c
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (22.11%)
 * Likes:    890
 * Dislikes: 0
 * Total Accepted:    160K
 * Total Submissions: 723.6K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)

int divide(int dividend, int divisor){
    if (divisor == 1) {
        return dividend;
    } else if (divisor == -1) {
        if (dividend > INT_MIN) {
            return (0 - dividend);
        } else {
            return INT_MAX;
        }
    }
    
    int flag = 1;
    long divi = 0;
    long mpy = 1;
    long dividendl = dividend;
    long divisorl = divisor;
    if (dividend < 0) {
        flag = -1;
        dividendl = 0 - dividendl;
    }

    if (divisor < 0) {
        flag = 0 - flag;
        divisorl = 0 - divisorl;
    }

    while (divisorl <= dividendl) {
        divisorl = divisorl << 1;
        mpy = mpy << 1;
    }

    divisorl = divisorl >> 1;
    mpy = mpy >> 1;
    
    while (divisorl > 0) {
        //printf("X=%d, Y=%d, Z=%d\n", dividendl, divisorl, divi);
        if (dividendl >= divisorl) {       
            dividendl -= divisorl;
            divi += mpy;
        } else if (mpy > 1) {
            divisorl = divisorl >> 1;
            mpy = mpy >> 1;
        } else {
            break;
        }
    }

    if (flag == -1) {
        return (0 - divi);
    }
    
    return (divi);
}
// @lc code=end

