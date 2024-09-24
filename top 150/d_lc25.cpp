#include "../header/listnode.h"

/**
 * k个一组，链表反转
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150
 */

/**
 * 反转从head到tail的所有链表(不包括head)
 * 返回链表的尾巴
 */
ListNode* reverseNode(ListNode* head, ListNode* tail) {
  ListNode* lastNode = tail->next;
  ListNode* tempNode = head->next;
  while (lastNode == NULL || lastNode != tail) {
    ListNode* next = tempNode->next;
    tempNode->next = lastNode;
    lastNode = tempNode;
    tempNode = next;
  }
  ListNode* ret = head->next;
  head->next = tail;
  return ret;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* tempHead = new ListNode();
  tempHead->next = head;

  ListNode* start = tempHead;
  ListNode* tail = tempHead;
  int count = 0;
  while (tail != NULL) {
    tail = tail->next;
    if (tail != NULL) {
      count++;
    }
    if (count >= k) {
      start = reverseNode(start, tail);
      tail = start;
      count = 0;
    }
  }
  return tempHead->next;
}

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6, 7, 8};
  ListNode* head = buildList(input, 8);
  printList(reverseKGroup(head, 3));
  return 0;
}
