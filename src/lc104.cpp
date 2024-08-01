#include <unordered_map>
#include <vector>

#include "../header/treenode.h"

using namespace std;

int maxDepth(TreeNode* root) {
  unordered_map<TreeNode*, int> map;
  deque<TreeNode*> queue;
  int maxDepth = 0;
  queue.push_back(root);
  map.insert(make_pair(root, 1));
  while (!queue.empty()) {
    TreeNode* front = queue.front();
    queue.pop_front();
    auto pair = map.find(front);
    int depth = 0;
    if (pair != map.end()) {
      depth = pair->second;
    }
    // 到底了
    if (front->left == NULL && front->right == NULL) {
      if (maxDepth < depth) {
        maxDepth = depth;
      }
      continue;
    }
    if (front->left != NULL) {
      map.insert(make_pair(front->left, depth + 1));
      queue.push_back(front->left);
    }
    if (front->right != NULL) {
      map.insert(make_pair(front->right, depth + 1));
      queue.push_back(front->right);
    }
  }
  return maxDepth;
}

int maxDepthLayerWay(TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  deque<TreeNode*> queue;
  queue.push_back(root);
  int ans = 1;
  while (!queue.empty()) {
    vector<TreeNode*> tempVector;
    while (!queue.empty()) {
      TreeNode* front = queue.front();
      queue.pop_front();
      if (front->left != NULL) {
        tempVector.push_back(front->left);
      }
      if (front->right != NULL) {
        tempVector.push_back(front->right);
      }
    }
    if (!tempVector.empty()) {
      for (TreeNode* node : tempVector) {
        queue.push_back(node);
      }
      ans++;
    }
  }
  return ans;
}