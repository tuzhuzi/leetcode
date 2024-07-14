#include "../header/listnode.h"

/**
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 */

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *tempHead = (ListNode *)malloc(sizeof(ListNode));
    tempHead->next = head;
    ListNode *nextNode = tempHead;
    ListNode *deleteParent = NULL;
    int index = n;
    while (nextNode != NULL)
    {
        if (n == 0)
        {
            if (deleteParent == NULL)
            {
                deleteParent = tempHead;
            }
            else
            {
                deleteParent = deleteParent->next;
            }
        }
        else
        {
            n--;
        }
        nextNode = nextNode->next;
    }
    ListNode *deleteNode = deleteParent->next;
    if (deleteNode == NULL)
    {
        return head;
    }
    deleteParent->next = deleteNode->next;
    if (head == deleteNode)
    {
        return head->next;
    }
    return head;
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
    int deleteIndex;
    scanf("%d", &deleteIndex);
    ListNode *head = buildList(nums, length);
    printList(removeNthFromEnd(head, deleteIndex));
    return 0;
}
