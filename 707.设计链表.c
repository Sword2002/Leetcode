/*
 * @lc app=leetcode.cn id=707 lang=c
 *
 * [707] 设计链表
 *
 * https://leetcode-cn.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (26.26%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 78.1K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\r\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]\r'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 * 
 * 在链表类中实现这些功能：
 * 
 * 
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 * 
 * 
 */

// @lc code=start



typedef struct _MyList {
    int value;
    struct _MyList *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* l = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    l->value= -1;
    l->next = NULL;
    return l;
}


/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    
    if(index<0) return -1;
    
    MyLinkedList* cur = obj->next;
    int i = 0;

    while (cur)
    {
        if (i++ == index)
        {
            //printf("get = %d\n", cur->value);
            return (cur->value);
        }
        cur = cur->next;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->value = val;
    head->next = obj->next;
    obj->next = head;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* cur = obj;
    while (cur->next)
    {
        cur = cur->next;
    }
    MyLinkedList *l1 = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    l1->next = NULL;
    l1->value = val;
    cur->next = l1;

}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (0 >= index)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }    
    
    MyLinkedList* cur = obj->next;
    int i = 1;
    while (cur)
    {
        if (i++ == index)
        {
            break;
        }
        cur = cur->next;
    }

    if (cur)
    {
        MyLinkedList *l1 = (MyLinkedList *)malloc(sizeof(MyLinkedList));
        l1->next = cur->next;
        l1->value = val;
        cur->next = l1;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* cur = obj;
    obj = obj->next;
    int i = 0;
    while (obj)
    {
        if (i++ == index)
        {
            break;
        }
        cur = obj;
        obj = obj->next;
    }

    if (obj) 
    {
        cur->next = obj->next;
        free(obj);
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* cur;

    while(obj){
        cur=obj;
        obj=cur->next;
        free(cur);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
// @lc code=end

