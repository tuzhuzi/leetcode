#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(vector<int> candidates, int startIndex, int tempSum, int target,
         vector<int>& path, vector<vector<int>>& output) {
  if (tempSum == target) {
    output.push_back(vector<int>(path));
    return;
  }
  for (int i = startIndex; i < candidates.size(); i++) {
    path.push_back(candidates[i]);
    tempSum += candidates[i];
    if (tempSum > target) {
      path.pop_back();
      break;
    }
    dfs(candidates, i, tempSum, target, path, output);
    tempSum -= candidates[i];
    path.pop_back();
  }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<int> path;
  vector<vector<int>> output;
  sort(candidates.begin(), candidates.end());
  dfs(candidates, 0, 0, target, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{2, 3, 6, 7};
  vector<vector<int>> output = combinationSum(input, 7);
  for (vector<int> vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
