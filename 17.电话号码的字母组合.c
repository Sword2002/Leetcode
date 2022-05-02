/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.73%)
 * Likes:    1858
 * Dislikes: 0
 * Total Accepted:    468.6K
 * Total Submissions: 811.5K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define PHONE_NUM 8
typedef struct PHONTAB {
    char str[5];
    int slen;
};

struct PHONTAB Phone2AlphaTab[PHONE_NUM] = {
    {"abc",   3}, // '2'
    {"def",   3}, // '3'
    {"ghi",   3}, // '4'
    {"jkl",   3}, // '5'
    {"mon",   3}, // '6'
    {"pqrs",  4}, // '7'
    {"tuv",   3}, // '8'
    {"wxyz",  4}, // '9'
};

void dfsFunc(char *digits, int dlen, int depth, char *str, char **ans, int *index)
{
    int i;
    int j = (int)(digits[depth] - '2');

    if (depth == dlen - 1) { // 最后一层
        for (i = 0; i < Phone2AlphaTab[j].slen; i++) {
            char *strx = (char *)malloc(dlen + 1);
            char *strs = str;
            memset(strx, 0, dlen + 1);
            ans[*index] = strx;

            while (*strs) {
                *strx++ = *strs++;
            }
            *strx++ = Phone2AlphaTab[j].str[i];
            //printf("outx = %s, index = %d\n", ans[*index], *index);
            (*index)++;
        }
        return;
    }

    for (i = 0; i < Phone2AlphaTab[j].slen; i++) {
        *(str + depth) = Phone2AlphaTab[j].str[i]; // 加上这一层的字符
        *(str + depth + 1) = '\0';
        dfsFunc(digits, dlen, depth + 1, str, ans, index);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    // 0 <= digits.length <= 4, 所以, 最多是: 4*4*3*3 = 144
    char **ans = (char **)malloc(sizeof(char *) * 144);
    // 检查是否申请成功
    // TBD
    memset(ans, 0, sizeof(char *) * 144);

    int dlen = strlen(digits);
    if (dlen == 0) {
        *returnSize = 0;
        return ans;
    }
    
    int index = 0;
    char *strx = (char *)malloc(5);
    memset(strx, 0, 5);

    dfsFunc(digits, dlen, 0, strx, ans, &index);
    *returnSize = index;
    //printf("returnSize = %d\n", *returnSize);

    return ans;
}

// @lc code=end