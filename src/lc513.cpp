#include <cstdio>
#include <deque>
#include <vector>

#include "../header/treenode.h"

int findBottomLeftValue(TreeNode* root) {
  deque<TreeNode*> queue;
  vector<TreeNode*> tempVector;
  int output = -1;
  queue.push_back(root);
  while (!queue.empty()) {
    tempVector.clear();
    for (TreeNode* node : queue) {
      if (node->left != NULL) {
        tempVector.push_back(node->left);
      }
      if (node->right != NULL) {
        tempVector.push_back(node->right);
      }
    }
    if (!tempVector.empty()) {
      queue.clear();
      for (TreeNode* node : tempVector) {
        queue.push_back(node);
      }
    } else {
      output = queue.front()->val;
      break;
    }
  }
  return output;
}

int main(int argc, char const* argv[]) {
  int output[]{1, 2, 3, 4, 5, 6, 7};
  TreeNode* node = buildTreeNode(output, 7);
  printf("%d", findBottomLeftValue(node));
  return 0;
}
