/*
 * @lc app=leetcode.cn id=166 lang=c
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (26.08%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 45.2K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */

// @lc code=start
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * fractionToDecimal(int numerator, int denominator){
    if (denominator == 0) {
        return NULL;
    }
    
    char *res = malloc(sizeof(char) * 128);
    memset(res, 0, 128);

    if (numerator == 0) {
        res[0] = '0';
        return res;
    }

    int idex = 0;
    int flag = 1;
    long n = (long)numerator;
    long d = (long)denominator;
    if (n < 0) {
        flag *= -1;
        n *= -1;
    }    
    if (d < 0) {
        flag *= -1;
        d *= -1;
    }

    if (flag == -1) {
        res[idex++] = '-';
    }

    // 余数出现重复时，小数开始循环
    int **map = malloc(sizeof(int*) * d);
    for (int i = 0; i < d; i++) {
        map[i] = malloc(sizeof(int) * 2);
        memset(map[i], 0, sizeof(int) * 2);
    }
    

    int x = n / d;
    if (x != 0) {
        int base = 1000000000;
        while (x < base) {
            base /= 10;
        }

        while (base) {
            res[idex++] = '0' + x / base;
            x %= base;
            base /= 10;
        }
    } else {
        res[idex++] = '0';
    } 


    x = n % d;
    if (x == 0) {
        return res;
    }
    res[idex++] = '.';
    while (x) {
        if (map[x][0] == 1) {
            res[idex+1] = ')';
            int ist = map[x][1];
            for (int i = idex; i > ist; i--) {
                res[i] = res[i-1];
            }
            res[ist] = '(';
            break;
        }
        map[x][0] = 1;
        map[x][1] = idex;
        x *= 10;
        res[idex++] = '0' + x/d;
        x %= d;
    }
    return res;
}


// @lc code=end

