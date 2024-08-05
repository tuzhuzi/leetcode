#include <vector>

#include "../header/treenode.h"

using namespace std;

TreeNode *buildEqualBinaryTreeNode(vector<int> nums, int left, int right) {
  if (left > right) {
    return NULL;
  }
  int mid = (left + right) / 2;
  TreeNode *node = new TreeNode();
  node->val = nums[mid];
  node->left = buildEqualBinaryTreeNode(nums, left, mid - 1);
  node->right = buildEqualBinaryTreeNode(nums, mid + 1, right);
  return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums) {
  return buildEqualBinaryTreeNode(nums, 0, nums.size() - 1);
}