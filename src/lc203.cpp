#include "stdio.h"
#include "../header/listnode.h"

/**
 * 移除鏈錶元素
 * https://leetcode.cn/problems/remove-linked-list-elements/
 */

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *firstNode = (ListNode *)malloc(sizeof(ListNode));
    firstNode->next = head;
    ListNode *tempHead = firstNode;
    while (tempHead->next != NULL)
    {
        ListNode *next = tempHead->next;
        if (next->val != val)
        {
            tempHead = next;
            continue;
        }
        tempHead->next = next->next;
    }
    return firstNode->next;
}

int main(int argc, char const *argv[])
{
    int length;
    scanf("%d", &length);
    int nums[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", nums + i);
    }
    ListNode *head = buildList(nums, length);
    head = removeElements(head, 2);
    printList(head);
    return 0;
}
