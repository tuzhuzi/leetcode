#include <deque>

#include "../header/treenode.h"

bool checkSum(TreeNode* node, int targetSum, int sum) {
  if (node == NULL) {
    return false;
  }
  sum += node->val;
  if (node->left == NULL && node->right == NULL) {
    return sum == targetSum;
  }
  return checkSum(node->left, targetSum, sum) ||
         checkSum(node->right, targetSum, sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
  return checkSum(root, targetSum, 0);
}