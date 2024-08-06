#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(vector<int> candidate, int startindex, int target, int tempSum,
         vector<int>& path, vector<vector<int>>& output) {
  if (tempSum == target) {
    output.push_back(vector<int>(path));
    return;
  }
  int i = startindex;
  while (i < candidate.size()) {
    int lastValue = candidate[i];
    tempSum += lastValue;
    if (tempSum > target) {
      break;
    }
    path.push_back(lastValue);
    dfs(candidate, i + 1, target, tempSum, path, output);
    path.pop_back();
    tempSum -= lastValue;
    while (i < candidate.size() && candidate[i] == lastValue) {
      i++;
    }
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<int> path;
  vector<vector<int>> output;
  dfs(candidates, 0, target, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{2, 2, 2, 1, 5};
  vector<vector<int>> output = combinationSum2(input, 5);
  for (vector<int> vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
