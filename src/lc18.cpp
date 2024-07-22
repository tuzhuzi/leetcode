#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> outPut;

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < nums.size(); j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue;
      }
      int sum = target - nums[i] - nums[j];
      int p = nums.size() - 1;
      for (int k = j + 1; k < nums.size(); k++) {
        if (k > j + 1 && nums[k] == nums[k - 1]) {
          continue;
        }
        while (p > k && nums[p] + nums[k] > sum) {
          p--;
        }
        if (p <= k) {
          break;
        }
        if (nums[p] + nums[k] == sum) {
          outPut.push_back({nums[i], nums[j], nums[k], nums[p]});
        }
      }
    }
  }
  return outPut;
}

int main(int argc, char const* argv[]) {
  vector<int> input = {1, 0, -1, 0, -2, 2};
  int target = 0;
  for (vector<int> output : fourSum(input, target)) {
    printf("%d %d %d %d \n", output[0], output[1], output[2], output[3]);
  }
  return 0;
}
