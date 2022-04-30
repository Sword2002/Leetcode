/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (47.56%)
 * Likes:    653
 * Dislikes: 0
 * Total Accepted:    122.4K
 * Total Submissions: 256.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start


char * convert(char * s, int numRows){

    int len =  strlen(s);
    char *zch = (char *)malloc(len+1);
    memset(zch, 0, (len+1));
    if ((1 >= numRows) || (numRows >= len))
    {
        return s;
    }

    int k = 0, j = 0, index = 0;
    int di = 2*numRows - 2; // numRows >= 2
    for (int i = 0; i < numRows; i++)
    {
        if (0 == i || ((numRows-1) == i))
        {
            k = 0;
            while((i + k*di) < len){     // i + k * 2(numRows - 1)
                zch[j++] = s[i + k*di];
                k++;
            }
            continue;
        }

        k = 0;
        while(((k*di - i) < len) || ((i + k*di) < len)){
            if (0 < (k*di - i) && (k*di - i) < len)
            {
                zch[j++] = s[k*di - i];
            } 
                
            if ((k*di + i) < len)
            {
                zch[j++] = s[k*di + i];
            } 
            k++;
        }
    }

    return zch;
}


// @lc code=end

