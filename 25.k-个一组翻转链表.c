/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (58.17%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    52.1K
 * Total Submissions: 89.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int lenList(struct ListNode* head){
    int k = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        k++;
        cur = cur->next;
    }

    return k;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    
    if (k <= 1) { return head;} // 不需要交换

    int len = lenList(head);
    printf("%d\n",len);
    
    int times = len / k;
    int i = 0, j = 0;

    struct ListNode *cur, *pre, *thead, *dummy;
    struct ListNode *tear = (struct ListNode *)malloc(sizeof(struct ListNode));
    thead = head;
    dummy = tear;
    pre = head;
    cur = head->next;

    for (i = 0; i < times; i++)
    {
        for (j = 0; j < (k-1); j++)
        {
            pre->next = cur->next;
            cur->next = thead;
            thead = cur;
            cur = pre->next;
        }
        
        if (0 == i) // 记录链表头
        {
            dummy = thead;
        }

        tear->next = thead;
        if (cur) // 到下一轮，cur==NULL,说明结束了
        {
            tear = pre;
            pre = cur;
            cur = cur->next;
            thead = pre;
        } else {
            break;
        }       
    }


    return dummy;
}





// @lc code=end

