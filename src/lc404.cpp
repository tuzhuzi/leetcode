#include <cstdio>

#include "../header/treenode.h"

int countSumOfTree(TreeNode* node, bool isLeft) {
  if (node == NULL) {
    return 0;
  }
  if (isLeft && node->left == NULL && node->right == NULL) {
    return node->val;
  }
  return countSumOfTree(node->left, true) + countSumOfTree(node->right, false);
}

int sumOfLeftLeaves(TreeNode* root) { return countSumOfTree(root, false); }

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5};
  TreeNode* node = buildTreeNode(input, 5);
  printf("%d", sumOfLeftLeaves(node));
  return 0;
}
