#include <cstdio>
#include <vector>

using namespace std;

void dfs(vector<int> nums, int startIndex, vector<int>& path,
         vector<vector<int>>& output) {
  output.push_back(path);
  for (int i = startIndex; i < nums.size(); i++) {
    path.push_back(nums[i]);
    dfs(nums, i + 1, path, output);
    path.pop_back();
  }
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> output;
  vector<int> path;
  dfs(nums, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3};
  auto output = subsets(input);
  for (vector<int> vec : output) {
    for (int val : vec) {
      printf("%d ", val);
    }
    printf("\n");
  }
  return 0;
}
