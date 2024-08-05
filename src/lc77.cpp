#include <vector>
using namespace std;

void dfs(int n, int k, int startIndex, vector<int> &path,
         vector<vector<int>> &output) {
  if (path.size() == k) {
    output.push_back(vector<int>(path));
    return;
  }
  for (int i = startIndex; i < n; i++) {
    path.push_back(i + 1);
    dfs(n, k, i + 1, path, output);
    path.pop_back();
  }
}

vector<vector<int>> combine(int n, int k) {
  // 用深度优先的思路来写
  vector<int> path;
  vector<vector<int>> output;
  dfs(n, k, 0, path, output);
  return output;
}