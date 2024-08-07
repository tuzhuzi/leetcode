#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

// 去重这是一种方案， 另一种方案参考lc40
void dfs(vector<int> nums, int startIndex, vector<int>& path,
         vector<vector<int>>& output) {
  output.push_back(vector<int>(path));
  int lastIndex = startIndex;
  int index = lastIndex;
  while (index < nums.size()) {
    int val = nums[index++];
    path.push_back(val);
    if (index < nums.size() && nums[index] != val || index == nums.size()) {
      for (int i = lastIndex; i < index; i++) {
        dfs(nums, index, path, output);
        path.pop_back();
      }
      lastIndex = index;
    }
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<int> path;
  vector<vector<int>> output;
  sort(nums.begin(), nums.end());
  dfs(nums, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 1, 2};
  vector<vector<int>> output = subsetsWithDup(input);
  for (auto vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
