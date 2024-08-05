#include <cstdio>
#include <vector>

using namespace std;

void dfs(int k, int n, int tempSum, int start, vector<int>& path,
         vector<vector<int>>& output) {
  if (path.size() == k) {
    if (tempSum == n) {
      output.push_back(vector<int>(path));
    }
    return;
  }
  for (int i = start; i <= (n - tempSum) && i <= 9; i++) {
    path.push_back(i);
    tempSum += i;
    dfs(k, n, tempSum, i + 1, path, output);
    tempSum -= i;
    path.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<int> path;
  vector<vector<int>> output;
  int tempSum = 0;
  dfs(k, n, tempSum, 1, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> output = combinationSum3(3, 9);
  for (vector<int> vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
