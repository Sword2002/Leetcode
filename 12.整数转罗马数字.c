/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 *
 * https://leetcode-cn.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (63.26%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    84.4K
 * Total Submissions: 133.2K
 * Testcase Example:  '3'
 *
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
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
 * 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: "III"
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "IV"
 * 
 * 示例 3:
 * 
 * 输入: 9
 * 输出: "IX"
 * 
 * 示例 4:
 * 
 * 输入: 58
 * 输出: "LVIII"
 * 解释: L = 50, V = 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: 1994
 * 输出: "MCMXCIV"
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */

// @lc code=start
#define RNTAB_LEN 13
#define BUFF_LEN 32

struct ROMAN
{
    int num;
    char ch[3];
};

const struct ROMAN RomNumTab[RNTAB_LEN] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};


char srlt[BUFF_LEN] = "";

// 这个代码的优点是简短
char * intToRoman(int num){
    int x = num;
    int k = 0;
    int i = 0;
    memset(srlt, 0, BUFF_LEN);
    while (i < RNTAB_LEN) {
        while (x >= RomNumTab[i].num) {
            strcat(srlt, RomNumTab[i].ch);
            x -= RomNumTab[i].num;
        }
        i++;
    }

    return srlt;
}

#if 0
char * intToRoman(int num){
    int x = num;
    int k = 0;
    while(1000 <= x)
    {
        srlt[k++]='M';
        x -= 1000;
    }
    
    if (900 <= x)
    {
        srlt[k++]='C';
        srlt[k++]='M';
        x -= 900;
    }

    if (500 <= x)
    {
        srlt[k++]='D';
        x -= 500;
    }

    if (400 <= x)
    {
        srlt[k++]='C';
        srlt[k++]='D';
        x -= 400;
    }

    while(100 <= x)
    {
        srlt[k++]='C';
        x -= 100;
    }
    if (90 <= x)
    {
        srlt[k++]='X';
        srlt[k++]='C';
        x -= 90;
    }

    if (50 <= x)
    {
        srlt[k++]='L';
        x -= 50;
    }

    if (40 <= x)
    {
        srlt[k++]='X';
        srlt[k++]='L';
        x -= 40;
    }

    while(10 <= x)
    {
        srlt[k++]='X';
        x -= 10;
    }

    if (9 <= x)
    {
        srlt[k++]='I';
        srlt[k++]='X';
        x -= 9;
    }

    if (5 <= x)
    {
        srlt[k++]='V';
        x -= 5;
    }

    if (4 <= x)
    {
        srlt[k++]='I';
        srlt[k++]='V';
        x -= 4;
    }

    while(1 <= x)
    {
        srlt[k++]='I';
        x -= 1;
    }
    srlt[k++] = '\0';     
    return (srlt);
}
#endif

// @lc code=end

