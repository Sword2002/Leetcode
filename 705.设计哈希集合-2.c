/*
 * @lc app=leetcode.cn id=705 lang=c
 *
 * [705] 设计哈希集合
 *
 * https://leetcode-cn.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (56.45%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 23.9K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合
 * 
 * 具体地说，你的设计应该包含以下的功能
 * 
 * 
 * add(value)：向哈希集合中插入一个值。
 * contains(value) ：返回哈希集合中是否存在这个值。
 * remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例:
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // 返回 true
 * hashSet.contains(3);    // 返回 false (未找到)
 * hashSet.add(2);          
 * hashSet.contains(2);    // 返回 true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // 返回  false (已经被删除)
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 所有的值都在 [0, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希集合库。
 * 
 * 
 */

// @lc code=start

#define SIZE (1000001/8)
typedef struct {
    unsigned char * hash;
} MyHashSet;
 
/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* H = (MyHashSet*)malloc(sizeof(MyHashSet));
    H->hash = (unsigned char *)malloc(sizeof(unsigned char)* SIZE);
    memset(H->hash,0,sizeof(unsigned char)* SIZE);
    return H;
}
 
void myHashSetAdd(MyHashSet* obj, int key) {
    int pos = key / 8;
    int t = key % 8;
    obj->hash[pos] |= 1 << t ;
}
 
void myHashSetRemove(MyHashSet* obj, int key) {
    int pos = key / 8;
    int t = key%8;
    obj->hash[pos] &= ~(1 << t) ;
}
 
/** Returns true if this set did not already contain the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int pos = key / 8;
    int t = key%8;
    return obj->hash[pos] & (1 << t) ;
   
}
 
void myHashSetFree(MyHashSet* obj) {
    free(obj->hash);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
// @lc code=end

