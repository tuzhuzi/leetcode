#include "../header/treenode.h"

TreeNode* invertTree(TreeNode* root) {
  if (root == NULL) {
    return root;
  }
  TreeNode* leftNode = root->left;
  TreeNode* rightNode = root->right;
  root->left = rightNode;
  root->right = leftNode;
  invertTree(leftNode);
  invertTree(rightNode);
  return root;
}

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  TreeNode* head = buildTreeNode(input, 9);
  head = invertTree(head);
  layerPrintNode(head);
  return 0;
}
