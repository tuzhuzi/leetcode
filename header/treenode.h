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

void addBinaryTreeNode(TreeNode* head, int val) {
  if (val >= head->val) {
    if (head->right == NULL) {
      head->right = new TreeNode();
      head->right->val = val;
      return;
    }
    addBinaryTreeNode(head->right, val);
  } else {
    if (head->left == NULL) {
      head->left = new TreeNode();
      head->left->val = val;
      return;
    }
    addBinaryTreeNode(head->left, val);
  }
}

// 二叉搜索树， 大概率不平衡
TreeNode* buildBinaryTreeNode(int* arr, int length) {
  if (length == 0) {
    return NULL;
  }
  TreeNode* head = new TreeNode();
  head->val = arr[0];
  for (int i = 1; i < length; i++) {
    addBinaryTreeNode(head, arr[i]);
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

// 中序遍历
void midPrintNode(TreeNode* head) {
  if (head == NULL) {
    return;
  }
  midPrintNode(head->left);
  printf("%d ", head->val);
  midPrintNode(head->right);
}

// 层级遍历
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
