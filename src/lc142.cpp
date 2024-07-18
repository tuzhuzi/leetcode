#include "../header/listnode.h"
#include <unordered_set>
using namespace std;

/**
 * 找到环形链表的入口
 * https://leetcode.cn/problems/linked-list-cycle-ii/description/
 */
ListNode *detectCycleNode(ListNode *head)
{
    unordered_set<ListNode *> hashSet;

    while (true)
    {
        if (hashSet.count(head))
        {
            return head;
        }
        hashSet.insert(head);
        head = head->next;
    }
    return NULL;
}
