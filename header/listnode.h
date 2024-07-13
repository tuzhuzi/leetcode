#include "stdio.h"
#include <malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

ListNode *buildList(int *nums, int length);

void printList(ListNode *head);

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

ListNode *buildList(int *nums, int length)
{
    if (length == 0)
    {
        return NULL;
    }
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *tempHead = head;
    for (int i = 0; i < length; i++)
    {
        ListNode *next = (ListNode *)malloc(sizeof(ListNode));
        next->next = NULL;
        next->val = nums[i];
        head->next = next;
        head = next;
    }
    return tempHead->next;
}