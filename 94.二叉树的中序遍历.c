/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.12%)
 * Likes:    515
 * Dislikes: 0
 * Total Accepted:    163.7K
 * Total Submissions: 228.8K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
#if 1

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    
    int *out = (int *)malloc(sizeof(int) * 1024);
    memset(out, 0, sizeof(int) * 1024);
    int outs = 0;

    struct TreeNode *stack[1024] = {0};
    int nodes = -1;
    
    while ((root != NULL) || (nodes >= 0)) {
        while (root != NULL) {
            stack[++nodes] = root;
            
            root = root->left;
        } 

        if (nodes >= 0) {
            root = stack[nodes];
            stack[nodes--] = NULL;
            out[outs++] = root->val;
            root = root->right;
        }
    }

    *returnSize = outs;
    return out;
}

#else
void treeInorder(struct TreeNode* root, int *out, int *idex) {
    if (root == NULL) {
        return;
    }

    treeInorder(root->left, out, idex);
    out[(*idex)++] = root->val;
    treeInorder(root->right, out, idex);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *out = (int *)malloc(sizeof(int) * 1024);
    memset(out, 0, sizeof(int) * 1024);
    treeInorder(root, out, returnSize);
    return out;
}
#endif
// @lc code=end

