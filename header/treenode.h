#include <cstdio>
#include <deque>

using namespace std;

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode() {
    left = NULL;
    right = NULL;
  }
};

TreeNode* buildTreeNode(int* arr, int length) {
  TreeNode* head = new TreeNode();
  head->val = arr[0];
  deque<TreeNode*> queue;
  queue.push_back(head);
  int index = 1;
  while (index < length && !queue.empty()) {
    TreeNode* front = queue.front();
    queue.pop_front();
    TreeNode* leftNode = new TreeNode();
    leftNode->val = arr[index++];
    front->left = leftNode;
    queue.push_back(leftNode);
    if (index < length) {
      TreeNode* rightNode = new TreeNode();
      rightNode->val = arr[index++];
      front->right = rightNode;
      queue.push_back(rightNode);
    }
  }
  return head;
}

// 前序遍历
void firstPrintNode(TreeNode* head) {
  if (head == NULL) {
    return;
  }
  printf("%d ", head->val);
  firstPrintNode(head->left);
  firstPrintNode(head->right);
}

// 层级便利
void layerPrintNode(TreeNode* head) {
  deque<TreeNode*> queue;
  queue.push_back(head);
  while (!queue.empty()) {
    TreeNode* front = queue.front();
    queue.pop_front();
    printf("%d ", front->val);
    if (front->left != NULL) {
      queue.push_back(front->left);
    }
    if (front->right != NULL) {
      queue.push_back(front->right);
    }
  }
}
