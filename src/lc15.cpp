#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

int calHash(int v1, int v2, int v3) { return v1 * 31 * 31 + v2 * 31 + v3; }

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> outPut;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int k = nums.size() - 1;
    for (int j = i + 1; j < nums.size(); j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue;
      }
      while (k > j && (nums[i] + nums[j] + nums[k]) > 0) {
        k--;
      }
      if (k <= j) {
        break;
      }
      if (nums[i] + nums[j] + nums[k] < 0) {
        continue;
      }
      outPut.push_back({nums[i], nums[j], nums[k]});
    }
  }
  return outPut;
}

int main(int argc, char const* argv[]) {
  vector<int> nums = {-2, 0, 1, 1, 2};
  for (vector<int> vec : threeSum(nums)) {
    printf("%d, %d, %d \n", vec[0], vec[1], vec[2]);
  }
  return 0;
}
