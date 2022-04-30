/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 *
 * https://leetcode-cn.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (59.15%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    76.2K
 * Total Submissions: 127.5K
 * Testcase Example:  '[["5','3','.','.','7','.','.','.','."],["6','.','.','1','9','5','.','.','."],[".','9','8','.','.','.','.','6','."],["8','.','.','.','6','.','.','.','3"],["4','.','.','8','.','3','.','.','1"],["7','.','.','.','2','.','.','.','6"],[".','6','.','.','.','.','2','8','."],[".','.','.','4','1','9','.','.','5"],[".','.','.','.','8','.','.','7','9"]]'
 *
 * 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 
 * 
 * 上图是一个部分填充的有效的数独。
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠ ["5','3','.','.','7','.','.','.','."],
 * ⁠ ["6','.','.','1','9','5','.','.','."],
 * ⁠ [".','9','8','.','.','.','.','6','."],
 * ⁠ ["8','.','.','.','6','.','.','.','3"],
 * ⁠ ["4','.','.','8','.','3','.','.','1"],
 * ⁠ ["7','.','.','.','2','.','.','.','6"],
 * ⁠ [".','6','.','.','.','.','2','8','."],
 * ⁠ [".','.','.','4','1','9','.','.','5"],
 * ⁠ [".','.','.','.','8','.','.','7','9"]
 * ]
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ["8','3','.','.','7','.','.','.','."],
 * ["6','.','.','1','9','5','.','.','."],
 * [".','9','8','.','.','.','.','6','."],
 * ["8','.','.','.','6','.','.','.','3"],
 * ["4','.','.','8','.','3','.','.','1"],
 * ["7','.','.','.','2','.','.','.','6"],
 * [".','6','.','.','.','.','2','8','."],
 * [".','.','.','4','1','9','.','.','5"],
 * [".','.','.','.','8','.','.','7','9"]
 * ]
 * 输出: false
 * 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
 * ⁠    但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
 * 
 * 说明:
 * 
 * 
 * 一个有效的数独（部分已被填充）不一定是可解的。
 * 只需要根据以上规则，验证已经填入的数字是否有效即可。
 * 给定数独序列只包含数字 1-9 和字符 '.' 。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
#include <stdbool.h>
#include <stdio.h>


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    if ((board == NULL) || (boardSize != 9) || (*boardColSize != 9)) {
        printf("input error\n");
        return false;
    }
    
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int tabs[9][9] = {0};
    for (int k = 0; k < boardSize; k++) {
        memset(rows[k], 0, sizeof(int) * 9);
        memset(cols[k], 0, sizeof(int) * 9);
        memset(tabs[k], 0, sizeof(int) * 9);
    } 

    int i = 0;
    int j = 0;
    int x = 0;
    int num;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            
            num = board[i][j] - '1';
            if ((num < 0) || (num > 8) || (rows[i][num] != 0)) {
                printf("rows,i=%d,j=%d,num=%d\n",i,j,num);
                return false;
            } else {
                rows[i][num] = 1;
            }
            if (cols[j][num] != 0) {
                printf("cols,i=%d,j=%d,num=%d\n",i,j,num);
                return false;
            } else {
                cols[j][num] = 1;
            }

            x = (i/3) * 3  + j/3;
            if (tabs[x][num] != 0) {
                printf("tabs,i=%d,j=%d,num=%d\n",i,j,num);
                return false;
            } else {
                tabs[x][num] = 1;
            }
        }
    }
    return true;
}

/*
[[".','8','7','6','5','4','3','2','1"],
 ["2','.','.','.','.','.','.','.','."],
 ["3','.','.','.','.','.','.','.','."],
 ["4','.','.','.','.','.','.','.','."],
 ["5','.','.','.','.','.','.','.','."],
 ["6','.','.','.','.','.','.','.','."],
 ["7','.','.','.','.','.','.','.','."],
 ["8','.','.','.','.','.','.','.','."],
 ["9','.','.','.','.','.','.','.','."]]
 */
// @lc code=end

