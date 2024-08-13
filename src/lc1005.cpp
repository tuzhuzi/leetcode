#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; i++) {
    nums[i] = -nums[i];
    k--;
  }
  if (k % 2 == 0) {
    return accumulate(nums.begin(), nums.end(), 0);
  }
  sort(nums.begin(), nums.end());
  nums[0] = -nums[0];
  return accumulate(nums.begin(), nums.end(), 0);
}