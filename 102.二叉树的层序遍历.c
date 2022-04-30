/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (61.61%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    142.5K
 * Total Submissions: 226.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode *p = root;
    struct TreeNode *nodeQueue[1024];
    int qpos= 0;
    int qtail = 0;

    int **res = (int **)malloc(sizeof(int *) * 1024);
    memset(res, 0, sizeof(int *) * 1024);

    //int (*a)[2]=(int(*)[2])malloc(sizeof(int)*3*2)
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 1024);
    memset(returnColumnSizes[0], 0, sizeof(int) * 1024);

    int level = -1;
    int idex = 0;

    p = root;
    nodeQueue[qpos++] = p;
    while (qpos > qtail) {
        int count = qpos - qtail;
        res[++level] = (int *)malloc(sizeof(int) * count);
        returnColumnSizes[0][level] = count;
        idex = 0;
        while(count > 0) {
            p = nodeQueue[qtail++];
            //printf("%d,%d,%d\n",level,idex,p->val);
            res[level][idex++] = p->val;

            if (p->left != NULL) {
                nodeQueue[qpos++] = p->left;
            }
            if (p->right != NULL) {
                nodeQueue[qpos++] = p->right;
            }
            count--;
        }
    }
    
    *returnSize = level+1;
    return res;
}


// @lc code=end

