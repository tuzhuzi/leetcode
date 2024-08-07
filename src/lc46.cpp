#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(vector<int> nums, unordered_set<int>& set, vector<int>& path,
         vector<vector<int>>& output) {
  if (path.size() == nums.size()) {
    output.push_back(vector<int>(path));
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
    if (set.find(nums[i]) != set.end()) {
      continue;
    }
    set.insert(nums[i]);
    path.push_back(nums[i]);
    dfs(nums, set, path, output);
    path.pop_back();
    set.erase(nums[i]);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<int> path;
  vector<vector<int>> output;
  unordered_set<int> set;
  dfs(nums, set, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3};
  auto output = permute(input);
  for (auto vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
