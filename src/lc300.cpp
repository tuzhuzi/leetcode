#include <cstdio>
#include <vector>

using namespace std;

/**
 * 最长严格递增子字符串
 * 先然后 dp[i] = dp[j] + 1{nums[j] < nums[i]}
 */
int lengthOfLIS(vector<int>& nums) {
  vector<int> dp(nums.size(), 1);
  int maxLength = 0;
  for (int i = 1; i < nums.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    maxLength = max(maxLength, dp[i]);
  }
  return maxLength;
}

int main(int argc, char const* argv[]) {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  printf("%d", lengthOfLIS(nums));
  return 0;
}
