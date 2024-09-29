#include <cstdio>
#include <vector>

using namespace std;

/**
 * 打家劫舍
 * 没看有啥特别的
 */
int rob(vector<int>& nums) {
  vector<int> dp(nums.size() + 1, 0);
  // dp初状态, dp[0] = 0, dp[i] = max{dp[i - 1], dp[i - 2] + nums[i]}
  for (int i = 1; i <= nums.size(); i++) {
    if (i < 2) {
      dp[i] = max(dp[i - 1], nums[i - 1]);
    } else {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
  }
  return dp[nums.size()];
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3, 1};
  printf("%d", rob(input));
  return 0;
}
