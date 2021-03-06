/*
 * @lc app=leetcode.cn id=621 lang=c
 *
 * [621] 任务调度器
 *
 * https://leetcode-cn.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (48.49%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 49.7K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * 给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26
 * 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU
 * 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
 * 
 * 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
 * 
 * 你需要计算完成所有任务所需要的最短时间。
 * 
 * 
 * 
 * 示例 ：
 * 
 * 输入：tasks = ["A","A","A","B","B","B"], n = 2
 * 输出：8
 * 解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
 * ⁠    在本示例中，两个相同类型任务之间必须间隔长度为 n = 2
 * 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 任务的总个数为 [1, 10000]。
 * n 的取值范围为 [0, 100]。
 * 
 * 
 */

// @lc code=start
#include "uthash.h"

struct TaskHash {
    int Id;
    int Count;
    UT_hash_handle hh;
};

int cmps(struct TaskHash *a, struct TaskHash *b) {
    return (a->Count - b->Count);
}

int cmpl(struct TaskHash *a, struct TaskHash *b) {
    return (b->Count - a->Count);
}

int leastInterval(char* tasks, int tasksSize, int n){
    struct TaskHash *th = NULL;
    struct TaskHash *add;
    int id;
    int TaskType = 0;
    int res = 0;
    for (int i = 0; i < tasksSize; i++) {
        id = tasks[i] - 'A';
        HASH_FIND_INT(th, &id, add);
        if (add == NULL) {
            add = malloc(sizeof(struct TaskHash));
            add->Id = id;
            add->Count = 1;
            HASH_ADD_INT(th, Id, add);
        } else {
            add->Count++;
        }
    }
    
    struct TaskHash *tmp;
    struct TaskHash *el;

    int i = 0;
    TaskType = HASH_COUNT(th);
    while (TaskType > 0) {
        HASH_SORT(th,cmpl);
        int j = 0;
        HASH_ITER(hh, th, el, tmp) {
            if ((el != NULL) && (j < TaskType) && (j <= n)) {
                res++;
                j++;
                el->Count--;
                if (el->Count == 0) {
                    HASH_DEL(th, el);
                }
            }
        }
        int redu = n - TaskType + 1;
        TaskType = HASH_COUNT(th);
        if ((TaskType > 0) && (redu >= 1)) {
            res += redu;
        }
    }
    return res;
}
// @lc code=end

