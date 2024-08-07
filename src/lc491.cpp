#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int startIndex, vector<int>& path,
         vector<vector<int>>& output) {
  if (path.size() >= 2) {
    output.push_back(vector<int>(path));
  }
  int index = startIndex;
  unordered_set<int> set;
  while (index < nums.size()) {
    int val = nums[index];
    if (set.find(val) == set.end()) {
      if (path.empty() || nums[index] >= path[path.size() - 1]) {
        path.push_back(nums[index]);
        set.insert(val);
        dfs(nums, index + 1, path, output);
        path.pop_back();
      }
    }
    while ((index < nums.size() && nums[index] == val)) {
      index++;
    }
  }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
  vector<int> path;
  vector<vector<int>> output;
  dfs(nums, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};
  auto output = findSubsequences(input);
  for (auto vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
