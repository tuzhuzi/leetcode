#include "../header/treenode.h"

void testBinaryTreeNode(int* input, int length) {
  TreeNode* head = buildBinaryTreeNode(input, length);
  // 二叉搜索树的先序遍历， 应当是排序
  midPrintNode(head);
}

int main(int argc, char const* argv[]) {
  int input[]{3, 1, 5, 6, 2, 4};
  testBinaryTreeNode(input, 6);
  return 0;
}
