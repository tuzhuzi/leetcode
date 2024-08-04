#include <unordered_set>

#include "../header/treenode.h"

TreeNode* findAncestor(TreeNode* head, unordered_set<int>& record, int p,
                       int q) {
  if (head == NULL) {
    return NULL;
  }
  unordered_set<int> tempRecord;
  TreeNode* findLeft = findAncestor(head->left, tempRecord, p, q);
  if (findLeft != NULL) {
    return findLeft;
  }
  for (int val : tempRecord) {
    record.insert(val);
  }
  tempRecord.clear();
  TreeNode* findRight = findAncestor(head->right, tempRecord, p, q);
  if (findRight != NULL) {
    return findRight;
  }
  for (int val : tempRecord) {
    record.insert(val);
  }
  record.insert(head->val);
  if (record.find(p) != record.end() && record.find(q) != record.end()) {
    return head;
  }
  return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  unordered_set<int> record;
  return findAncestor(root, record, p->val, q->val);
}

TreeNode* lowestCommonAncestor_standard(TreeNode* root, TreeNode* p,
                                        TreeNode* q) {
  if (root == p || root == q || root == NULL) {
    return root;
  }
  TreeNode* findLeft = lowestCommonAncestor_standard(root->left, p, q);
  TreeNode* findRight = lowestCommonAncestor_standard(root->right, p, q);
  // 左右都找到了子节点， root就是跟节点
  if (findLeft != NULL && findRight != NULL) {
    return root;
  }
  // 只找到一个节点，也尽早返回， 再后续合并
  // 如果没有合并过程，说明另一个节点也在该节点下
  if (findLeft == NULL) {
    return findRight;
  }
  return findLeft;
}

int main(int argc, char const* argv[]) {
  int input[]{1, 2, 3, 4, 5, 6};
  TreeNode* head = buildTreeNode(input, 6);
  unordered_set<int> record;
  TreeNode* ancestor = findAncestor(head, record, 5, 6);
  printf("%d ", ancestor->val);
  return 0;
}
