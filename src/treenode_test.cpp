#include "../header/treenode.h"

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6};
  TreeNode* head = buildTreeNode(input, 6);
  layerPrintNode(head);
  return 0;
}
