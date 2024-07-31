#include <vector>

#include "../header/treenode.h"

using namespace std;

bool cprNode(TreeNode* left, TreeNode* right) {
  if (left == NULL && right == NULL) {
    return true;
  }
  if (left == NULL || right == NULL) {
    return false;
  }
  if (left->val != right->val) {
    return false;
  }
  return cprNode(left->left, right->right) && cprNode(left->right, right->left);
}

bool isSymmetric(TreeNode* root) { return cprNode(root->left, root->right); }

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3};
  TreeNode* head = buildTreeNode(input, 3);
  printf("%d", isSymmetric(head));
  return 0;
}
