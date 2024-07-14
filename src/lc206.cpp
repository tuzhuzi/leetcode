#include "../header/listnode.h"

ListNode *reverseList(ListNode *head)
{
    ListNode *lastNode = NULL;
    ListNode *tempHead = head;
    while (tempHead != NULL)
    {
        ListNode *tempNext = tempHead->next;
        tempHead->next = lastNode;
        lastNode = tempHead;
        tempHead = tempNext;
    }
    return lastNode;
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
    printList(head);
    printf("\n");
    printList(reverseList(head));
    return 0;
}
