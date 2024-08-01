#include <cmath>

#include "../header/treenode.h"

// -1代表非平衡二叉树
int getHeight(TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);
  if (leftHeight == -1 || rightHeight == -1 ||
      abs(leftHeight - rightHeight) > 1) {
    return -1;
  }
  return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) { return getHeight(root) > 0; }

int main(int argc, char const* argv[]) { return 0; }
