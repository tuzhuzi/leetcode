#include "../header/listnode.h"

ListNode* mergeNodes(ListNode* head) {
  while (head != NULL && head->val == 0) {
    head = head->next;
  }
  ListNode* lastNode = head;
  while (lastNode != NULL && lastNode->next != NULL) {
    ListNode* next = lastNode->next;
    if (next->val != 0) {
      lastNode->val += next->val;
      lastNode->next = next->next;
      continue;
    }
    while (next != NULL && next->val == 0) {
      next = next->next;
    }
    lastNode->next = next;
    lastNode = next;
  }
  return head;
}

int main(int argc, char const* argv[]) {
  int input[]{0, 1, 0, 0, 2, 3, 0, 1, 2, 3, 0};
  ListNode* head = buildList(input, 11);
  ListNode* mergeHead = mergeNodes(head);
  printList(mergeHead);
  return 0;
}
