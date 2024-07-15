#include "../header/listnode.h"

/**
 * 链表的交叉节点
 * https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
 */

/**
 * 巧思,交叉节点双指针法
 * 假设 A为 a1, a2, c1, c2, c3
 * B为 b1, b2, b3, c1, c2, c3,
 * 则显而易见 a1, a2, c1, c2, c3, b1, b2, b3, c1
 * 和 b1, b2, b3, c1, c2, c3, a1, a2, c1
 * 长度相同
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct ListNode *pA = headA, *pB = headB;
    // 注意这里是直接比较指针地址的，所以构造测试用例的时候就要注意
    while (pA != pB)
    {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}