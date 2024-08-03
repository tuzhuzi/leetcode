#include <vector>

#include "../header/treenode.h"
using namespace std;

int findMaxIndex(vector<int> nums, int start, int end) {
  int tempValue = -__INT_MAX__;
  int maxIndex = -1;
  ;
  for (int i = start; i <= end; i++) {
    if (nums[i] > tempValue) {
      tempValue = nums[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}
TreeNode* buildNode(vector<int> nums, int start, int end) {
  if (start > end) {
    return NULL;
  }
  int maxIndex = findMaxIndex(nums, start, end);
  TreeNode* node = new TreeNode();
  node->val = nums[maxIndex];
  node->left = buildNode(nums, start, maxIndex - 1);
  node->right = buildNode(nums, maxIndex + 1, end);
  return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  return buildNode(nums, 0, nums.size() - 1);
}

int main(int argc, char const* argv[]) {
  vector<int> input({3, 2, 1, 6, 0, 5});
  TreeNode* node = buildNode(input, 0, 5);
  layerPrintNode(node);
  return 0;
}
