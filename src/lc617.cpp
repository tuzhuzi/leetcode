#include "../header/treenode.h"

TreeNode* mergeNode(TreeNode* a, TreeNode* b) {
  if (a == NULL) {
    return b;
  }
  if (b == NULL) {
    return a;
  }
  TreeNode* node = new TreeNode();
  node->val = a->val + b->val;
  node->left = mergeNode(a->left, b->left);
  node->right = mergeNode(a->right, b->right);
}
