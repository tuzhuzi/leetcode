#include "../header/treenode.h"

void testBinaryTreeNode(int* input, int length) {
  TreeNode* head = buildBinaryTreeNode(input, length);
  // 二叉搜索树的先序遍历， 应当是排序
  midPrintNode(head);
}

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6,7};
  TreeNode* tree = buildTreeNode(input, 7);
  firstPrintTreeNode_nonStack(tree);
  return 0;
}
