#include "../header/listnode.h"

ListNode *swapPairs(ListNode *head)
{
    ListNode *tempHead = head;
    ListNode *tempNext = NULL;

    while (tempHead != NULL)
    {
        tempNext = tempHead->next;
        if (tempNext == NULL)
        {
            break;
        }
        int tempNextVal = tempNext->val;
        tempNext->val = tempHead->val;
        tempHead->val = tempNextVal;
        tempHead = tempNext->next;
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
    ListNode *head = buildList(nums, length);
    swapPairs(head);
    printList(head);
    return 0;
}
