#include <deque>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "../header/treenode.h"

string dumpTreeNode(deque<TreeNode*> queue) {
  string s;
  for (TreeNode* node : queue) {
    if (!s.empty()) {
      s.append("->");
    }
    s.append(to_string(node->val));
  }
  return s;
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> output;
  if (root == NULL) {
    return output;
  }
  unordered_set<TreeNode*> record;
  deque<TreeNode*> queue;
  queue.push_back(root);
  record.insert(root);
  while (!queue.empty()) {
    TreeNode* back = queue.back();
    if (back->left == NULL && back->right == NULL) {
      output.push_back(dumpTreeNode(queue));
      queue.pop_back();
      continue;
    }
    if (back->left != NULL && record.find(back->left) == record.end()) {
      queue.push_back(back->left);
      record.insert(back->left);
      continue;
    }
    if (back->right != NULL && record.find(back->right) == record.end()) {
      queue.push_back(back->right);
      record.insert(back->right);
      continue;
    }
    queue.pop_back();
    continue;
  }
  return output;
}

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  TreeNode* head = buildTreeNode(input, 9);
  vector<string> dump = binaryTreePaths(head);
  for (string s : dump) {
    cout << s << endl;
  }
  return 0;
}
