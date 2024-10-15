#include <cstdio>
#include <deque>
#include <vector>

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

// 非递归的中序遍历
void midPrintTreeNodeNonStack(TreeNode* root) {
  deque<TreeNode*> stack;

  TreeNode* node = root;

  while (node != NULL || !stack.empty()) {
    if (node != NULL) {
      stack.push_back(node);
      node = node->left;
    } else {
      node = stack. back();
      stack.pop_back();
      printf("%d", node->val);
      node = node->right;
    }
  }
}

// 非递归的后续遍历
void lastPrintTreeNode_nonStack(TreeNode* node) {
  deque<TreeNode*> q;
  TreeNode* temp = node;
  // 记录访问过的右节点
  TreeNode* right = NULL;
  while (node != NULL || !q.empty()) {
    // 先尽量把左子树入队
    if (node != NULL) {
      q.push_back(node);
      node = node->left;
      continue;
    }
    // 已经没有左节点了，开始加入右节点
    if (q.back()->right != NULL && q.back()->right != right) {
      node = q.back()->right;
      // 标记下，避免后续重复访问
      continue;
    }
    // 输出节点
    printf("%d", q.back()->val);
    right = q.back();
    q.pop_back();
  }
}

void firstPrintTreeNode_nonStack(TreeNode* head) {
  TreeNode* node = head;
  deque<TreeNode*> q;
  TreeNode* lastAddedNode;
  
  while (node != NULL || !q.empty()) {
    // 先序遍历的话，就在入栈的时候先做打印
    if (node != NULL) {
      printf("%d", node->val);
      q.push_back(node);
      node = node->left;
      continue;
    }
    // 空节点了，开始插入右侧子节点，同样要避免节点被重复添加
    TreeNode* back = q.back();
    if (back->right != NULL && back->right != lastAddedNode) {
      node = back->right;
      continue;
    }
    // 这个节点已经访问完成，弹出栈顶
    lastAddedNode = back;
    q.pop_back();
  }
}

