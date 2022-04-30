/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (36.42%)
 * Likes:    5127
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.7M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start

int FindPalindrome(char * s, int slen, int mid, int *iLeft)
{
    int i, j;
    i = mid - 1;
    j = mid + 1;
    int max1 = 1;
    int max = 1;
    int left1, left2;

    left1 = mid;
    while (i >= 0 && j < slen && *(s + i) == *(s + j)) {
        max1 = j - i + 1;
        left1 = i;
        i--;
        j++;
    }

    i = mid;
    j = mid + 1;
    left2 = mid;
    while (i >= 0 && j < slen && *(s + i) == *(s + j)) {
        max = j - i + 1;
        left2 = i;
        i--;
        j++;
    }

    if (max > max1) {
        *iLeft = left2;
    } else {
        max = max1;
        *iLeft = left1;
    }

    return (max);
}

char * longestPalindrome(char * s)
{
    int slen = strlen(s);
    if (slen <= 1) {
        return s;
    }

    int mid;
    int max  = 1;
    int left = 0;
    int iLeft = 0;
    int l1;
    for (mid = 0; mid < slen; mid++) {
        l1 = FindPalindrome(s, slen, mid, &iLeft);
        if (l1 > max) {
            max = l1;
            left = iLeft;
        }
        //printf("l1 = %d, left = %d\n", l1, left);
        if (max >= slen || max >= 2 * (slen - mid)) {
            break;
        }
    }


    char *ret = (char *)malloc(max + 1);
    // 检查是否申请成功

    // 初始化
    memset(ret, 0, (max + 1));
    int i;
    for (i = 0; i < max; i++) {
        *(ret + i) = *(s + left + i);
    }

    return ret;
}
// @lc code=end

