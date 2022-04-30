/*
 * @lc app=leetcode.cn id=95 lang=c
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (62.46%)
 * Likes:    400
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 50K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTreesWithStartEnd(int start, int end, int* returnSize) {
    if (start >= end) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = start; i <= end; i++) {
        struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = i;
        int leftn = 0;
        struct TreeNode** lefts = generateTreesWithStartEnd(start, i-1, &leftn);
        int rightn = 0;
        struct TreeNode** rights = generateTrees(i+1, end, &rightn);
    }

}

struct TreeNode** generateTrees(int n, int* returnSize){
    if (n <= 0) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 1; i <= n; i++) {
        struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = i;
        int leftn = 0;
        struct TreeNode** lefts = generateTrees(i-1, &leftn);
        int rightn = 0;
        struct TreeNode** rights = generateTrees(i-1, &rightn);
    }
}
// @lc code=end

