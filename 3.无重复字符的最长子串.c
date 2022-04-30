/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (38.62%)
 * Likes:    7439
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 4.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    if (s == NULL || *s == '\0') {
        return 0;
    }

    char *flags = (char *)malloc(128 * sizeof(char));
    // 检查flags是否申请成功

    // 内存清零
    memset(flags, 0, sizeof(char) * 128);
    
    int lenMax = 1;
    int slen = strlen(s);
    int i = 0;
    int j = 1;
    while (i < slen - 1) {  // "abcabcbb" "bbbbb" "pwwkew"
        int len = j - i;
        *(flags + (int)*(s + i)) = 1;

        while (j < slen) {
            if (*(flags + (int)*(s + j)) == 0) {
                *(flags + (int)*(s + j)) = 1;
                len++;
                j++;
            } else {
                while (*(s + i) != *(s + j)) {
                    *(flags + (int)*(s + i)) = 0;
                    i++;
                }
                i++;
                j++;
                break;
            }
            //printf("s=%c\n", *(s + j));
        }

        lenMax = lenMax < len ? len : lenMax;
        // 剩下的字符串长度不会最大无重复子串长
        if (lenMax >= (slen - i)) {
            break;
        }
    }

    return lenMax;
}
// @lc code=end

