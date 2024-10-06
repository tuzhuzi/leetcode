#include <cstdio>
#include <vector>

using namespace std;

/**
 * 打家劫舍2，对象呈环形排列，意味着最后一户和第一户是连着的
 * 意味着需要针对是否偷第一户分别讨论
 */
int rob(vector<int>& nums) {
  vector<int> dp(nums.size() + 1, 0);
  int robFee;
  dp[0] = 0;
  // 偷第一户, 不偷最后一户
  dp[1] = nums[0];
  for (int i = 2; i <= nums.size() - 1; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }
  robFee = dp[nums.size() - 1];
  // 不偷第一户，偷最后一户
  dp[1] = 0;
  for (int i = 2; i <= nums.size(); i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }
  robFee = max(robFee, dp[nums.size()]);
  return robFee;
}

int main(int argc, char const* argv[]) {
  vector<int> input{2, 3, 2};
  printf("%d", rob(input));
  return 0;
}
