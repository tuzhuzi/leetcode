#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(vector<int> nums, vector<bool>& record, vector<int>& path,
         vector<vector<int>>& output) {
  if (path.size() == nums.size()) {
    output.push_back(vector<int>(path));
    return;
  }
  unordered_set<int> set;
  for (int i = 0; i < nums.size(); i++) {
    if (record[i] || set.find(nums[i]) != set.end()) {
      continue;
    }
    record[i] = true;
    set.insert(nums[i]);
    path.push_back(nums[i]);
    dfs(nums, record, path, output);
    path.pop_back();
    record[i] = false;
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<int> path;
  vector<vector<int>> output;
  vector<bool> record(nums.size(), false);
  dfs(nums, record, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 1, 2};
  auto output = permuteUnique(input);
  for (auto vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
