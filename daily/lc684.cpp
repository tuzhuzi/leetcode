#include <vector>
#include <cstdio>
using namespace std;

// 寻找根节点
int findParent(vector<int> parent, int index) {
  // 不是根节点
  if (parent[index] != index) {
    return findParent(parent, parent[index]);
  }
  return index;
}

// 合并节点，是让indexA和indexB指向同一个根节点
void combine(vector<int>& parent, int indexA, int indexB) {
  parent[findParent(parent, indexA)] = findParent(parent, indexB);
}

/**
 * https://leetcode.cn/problems/redundant-connection/solutions/557616/rong-yu-lian-jie-by-leetcode-solution-pks2/
 * 一个关于成环的有序题目， 当n个节点，所有节点都联通（树）时，需要n-1条边，而题目提供了n条边，所以导致了成环
 * 我们只需要找到成环的那条边即可
 * 当一条边的两个节点A和B，有相同的根节点时，显然AB边导致了成环
 */
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  int n = edges.size();
  vector<int> parent(n + 1, 0);
  for (int i = 0; i < parent.size(); i++) {
    parent[i] = i;
  }
  for (auto edge : edges) {
    // 有共同节点导致成环了，返回这条边
    if (findParent(parent, edge[0]) == findParent(parent, edge[1])) {
      return edge;
    }
    // 否则合并这两个节点
    combine(parent, edge[0], edge[1]);
  } 
  return vector<int>{0, 0};
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> input{{3, 7},  {1, 4}, {2, 8}, {1, 6}, {7, 9},
                            {6, 10}, {1, 7}, {2, 3}, {8, 9}, {5, 9}};
  auto repeat = findRedundantConnection(input);
  printf("%d %d", repeat[0], repeat[1]);
  return 0;
}
