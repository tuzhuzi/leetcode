#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void findPair(vector<int>& nums, int start, int left, int right, int target,
              vector<vector<int>>& output) {
  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum < target) {
      left++;
      while (left < right && nums[left] == nums[left - 1]) {
        left++;
      }
      continue;
    }
    if (sum > target) {
      right--;
      while (right > left && nums[right] == nums[right + 1]) {
        right--;
      }
      continue;
    }
    output.push_back(vector<int>{nums[start], nums[left], nums[right]});
    left++;
    while (left < right && nums[left] == nums[left - 1]) {
      left++;
    }
  }
}

/**
 * 三数之和， 双指针法
 */
vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> output;
  int left = 0;
  while (left < nums.size() - 2) {
    findPair(nums, left, left + 1, nums.size() - 1, -nums[left], output);
    left++;
    while (left < nums.size() - 2 && nums[left] == nums[left - 1]) {
      left++;
    }
  }
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input{-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
  for (auto& vec : threeSum(input)) {
    for (int v : vec) {
      printf("%d ", v);
    }
    printf("\n");
  }
  return 0;
}
