#include <cstdio>
#include <unordered_map>

#include "../header/treenode.h"


using namespace std;

/**
 * 树形结构的打劫问题
 * 定义g(node)为选中node的值
 * d(node)为不选择node的值
 * 显然有g(node) = d(node->left) + d(node->right) + node->val;
 * d(node) = max{d(node->left), g(node->left)} + max{d(node->right),
 * g(node->right)}
 */
struct GDVal {
  int selected;
  int noSelected;
  int max() { return std::max(selected, noSelected); }
};

GDVal dfs(TreeNode* node) {
  if (node == NULL) {
    return {0, 0};
  }
  GDVal lVal = dfs(node->left);
  GDVal rVal = dfs(node->right);
  GDVal nodeVal;
  nodeVal.selected = lVal.noSelected + rVal.noSelected + node->val;
  nodeVal.noSelected = lVal.max() + rVal.max();
  return nodeVal;
}

int rob(TreeNode* root) {
  GDVal val = dfs(root);
  return val.max();
}

int main(int argc, char const* argv[]) {
  int input[]{4, 2, 1};
  TreeNode* root = buildTreeNode(input, 3);
  printf("%d", rob(root));
  return 0;
}
