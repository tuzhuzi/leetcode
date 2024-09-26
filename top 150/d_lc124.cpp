#include <../header/treenode.h>

#include <cmath>


/**
 * 二叉树的最长路径问题
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-interview-150
 */

int getWeight(TreeNode* node, int& maxSum) {
  if (node == NULL) {
    return 0;
  }
  int leftWeight = max(getWeight(node->left, maxSum), 0);
  int rightWeight = max(getWeight(node->right, maxSum), 0);
  maxSum = max(maxSum, node->val + leftWeight + rightWeight);
  return max(node->val + leftWeight, node->val + rightWeight);
}

int maxPathSum(TreeNode* root) {
  int maxSum = 0;
  getWeight(root, maxSum);
  return maxSum;
}