/*
 * @lc app=leetcode.cn id=98 lang=c
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (29.87%)
 * Likes:    593
 * Dislikes: 0
 * Total Accepted:    123.6K
 * Total Submissions: 395.3K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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


int last = 0;
int flag = 0;
bool res = true;

bool inoderCheckBST(struct TreeNode* root) {

    if (root == NULL) {
        return true;
    }

    res &= inoderCheckBST(root->left);
    if (flag != 0 && last >= root->val) {
        return false;
    }
    last = root->val;
    flag = 1;
    res &= inoderCheckBST(root->right);
    return res;
}

bool isValidBST(struct TreeNode* root){     
    res = true;
    flag = 0;
    return inoderCheckBST(root);
}


// @lc code=end

