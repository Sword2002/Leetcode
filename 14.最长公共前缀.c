/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (37.00%)
 * Likes:    975
 * Dislikes: 0
 * Total Accepted:    237.5K
 * Total Submissions: 641.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){

    if (0 == strsSize) {                            // 输入空
        char *dummy = (char *)malloc(1);
        dummy[0] = 0;
        return dummy;                               // 返回的字符串""
    } else if (1 == strsSize) {                     // 只有一个字符串,就是他本身
        return strs[0];
    }
    int lmin = strlen((const char *)strs[0]);
    int i = 0, j = 0, k = 0;
    for (i = 1; i < strsSize; i++) {
        int len = strlen((const char *)strs[i]);
        if (len < lmin) {
            lmin = len;
        }
    }

    char *maxsame = (char *)malloc(lmin+1);
    memset((char *)maxsame, 0, (lmin+1));

    for (i = 0; i < lmin; i++) {
        char ch = strs[0][i];
        for (j = 1; j < strsSize; j++)  {
            if (ch != strs[j][i])
            {
                break;
            }
        } 

        if (j < strsSize) {
            break;
        }
        maxsame[k++] = ch;
    }

    return maxsame;
}


// @lc code=end

