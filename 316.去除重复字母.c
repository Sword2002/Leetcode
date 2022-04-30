/*
 * @lc app=leetcode.cn id=316 lang=c
 *
 * [316] 去除重复字母
 *
 * https://leetcode-cn.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (38.05%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    11.6K
 * Total Submissions: 30K
 * Testcase Example:  '"bcabc"'
 *
 * 
 * 给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: "bcabc"
 * 输出: "abc"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "cbacdcbc"
 * 输出: "acdb"
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 */

// @lc code=start

char * removeDuplicateLetters(char * s){
    
    // 特殊情况快速处理
    if (1 >= strlen(s)) {
        return s;
    }
    
    char record[26] = {0};
    int len = (int)strlen(s);
    int top = -1;
    char *stack = malloc(sizeof(char)*(len+1));
    //memset(record, 0, 26);
    //memset(stack, 0, (len+1));
    
    // 字符出现的次数
    for (int i=0; i<len; i++) {
        record[s[i]-'a']++;
    }
    
    for (int i=0; i<len; i++) {
        
        int isExist = 0;

        // 检查字符是否已经存在
        for (int j=0; j<=top; j++) {
            if (stack[j]==s[i]) {
                isExist = 1;
                record[s[i]-'a']--;
                break;
            }
        }
        
        //
        if (isExist==1) {
            continue;
        } else {
            if (top==-1 || s[i]>stack[top]) {
                stack[++top] = s[i];
                record[s[i]-'a']--;
            } else {
                while (top>=0 && record[stack[top]-'a']>0  && s[i]<stack[top]) {
                    top--;
                }
                stack[++top] = s[i];
                record[s[i]-'a']--;
            }
        }
    }
    
    stack[++top] = '\0';
    return stack;
}


// @lc code=end

