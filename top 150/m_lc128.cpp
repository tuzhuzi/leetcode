#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 寻找最长连续子数组，子数组不要求连续，不要求按顺序
 * 题目要求时间复杂度是On，我先写一个利用排序的非On复杂度
 */
int longestConsecutive(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int maxLegth = 1;
  int length = 1;
  int val = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      continue;
    }
    if (nums[i] == nums[i - 1] + 1) {
      length++;
      maxLegth = max(length, maxLegth);
      continue;
    }
    length = 1;
  }
  return maxLegth;
}