/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (61.32%)
 * Likes:    875
 * Dislikes: 0
 * Total Accepted:    186.5K
 * Total Submissions: 303.9K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */

// @lc code=start
#define RNTAB_LEN 15
struct ROMAN
{
    int num;
    char ch[3];
    int slen;
};

const struct ROMAN RomNumTab[RNTAB_LEN] = {
    {1000, "M",   1},
    {900,  "CM",  2},
    {500,  "D",   1},
    {400,  "CD",  2},
    {100,  "C",   1},
    {90,   "XC",  2},
    {50,   "L",   1},
    {40,   "XL",  2},
    {10,   "X",   1},
    {9,    "IX",  2},
    {5,    "V",   1},
    {4,    "IV",  2},
    {3,    "III", 3},
    {2,    "II",  2},
    {1,    "I",   1},
};

// 重构后代码简短
int romanToInt(char * s){
    int num  = 0;
    char * rs = s;
    int i = 0;
    while (*rs && i < RNTAB_LEN) {
        if (rs == strstr(rs, RomNumTab[i].ch)) { // 首位置开始匹配
            num += RomNumTab[i].num;
            rs += RomNumTab[i].slen;
            continue;
        }
        i++;
    }

    return num;
}

#if 0
int romanToInt(char * s){
    int num  = 0;
    while (*s)
    {
        char ch1 = *s;
        char ch2 = 0;
        switch (ch1)
        {
        case 'M':
            num += 1000;/* code */
            s++;
            break;
        case 'D':
            num += 500;/* code */
            s++;
            break;
         case 'L':
            num += 50;/* code */
            s++;
            break;
         case 'V':
            num += 5;/* code */
            s++;
            break;
         case 'C':
            ch2 = *(s+1);
            if ('M' == ch2) {
                num += 900;
                s++;
            } else if ('D' == ch2) {
                num += 400;
                s++;
            } else  {
                num += 100;
            }
            s++;
            break;
         case 'X':
            ch2 = *(s+1);
            if ('C' == ch2) {
                num += 90;
                s++;
            } else if ('L' == ch2) {
                num += 40;
                s++;
            } else  {
                num += 10;
            }
            s++;
            break;
         case 'I':
            ch2 = *(s+1);
            if ('X' == ch2) {
                num += 9;
                s++;
            } else if ('V' == ch2) {
                num += 4;
                s++;
            } else  {
                num += 1;
            }
            s++;
            break;       
        default:
            break;
        }
    }

    return num;
}
#endif

// @lc code=end

