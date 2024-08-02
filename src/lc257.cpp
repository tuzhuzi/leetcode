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

void dumpTreeTheRecursionWay(vector<string>& outPut, string path,
                             TreeNode* node) {
  if (node == NULL) {
    return;
  }
  path.append(to_string(node->val));
  if (node->left == NULL && node->right == NULL) {
    outPut.push_back(path);
    return;
  }
  path.append("->");
  dumpTreeTheRecursionWay(outPut, path, node->left);
  dumpTreeTheRecursionWay(outPut, path, node->right);
}

vector<string> dumpTreeTheRecursionWay(TreeNode* node) {
  vector<string> output;
  string path;
  dumpTreeTheRecursionWay(output, path, node);
  return output;
}

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  TreeNode* head = buildTreeNode(input, 9);
  vector<string> dump = dumpTreeTheRecursionWay(head);
  for (string s : dump) {
    cout << s << endl;
  }
  return 0;
}
