#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

// 用回溯法解题
void dfs(vector<int>& nums, int startIndex, int sum, int target, int& count) {
  if (startIndex == nums.size() && sum == target) {
    count++;
    return;
  }
  if (startIndex == nums.size()) {
    return;
  }
  dfs(nums, startIndex + 1, sum + nums[startIndex], target, count);
  dfs(nums, startIndex + 1, sum - nums[startIndex], target, count);
}

// 01背包方案
// 重要的是如何把这个问题转化为01背包
int findTargetDpWay(vector<int>& nums, int target) {
  int sum = 0;
  for (int num : nums) {
    sum += num;
  }
  if (target > sum || (sum - target) % 2 != 0) {
    return 0;
  }
  // negasum是组合中所有取负数的数字之和，这样就转换成了01背包了
  int negasum = (sum - target) / 2;
  vector<vector<int>> dp(nums.size() + 1, vector<int>(negasum + 1, 0));
  // dp初状态
  dp[0][0] = 1;
  // dp转移方程dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]
  for (int i = 1; i <= nums.size(); i++) {
    for (int j = negasum; j >= 0; j--) {
      dp[i][j] += dp[i - 1][j];
      if (j >= nums[i - 1]) {
        dp[i][j] += dp[i - 1][j - nums[i - 1]];
      }
    }
  }
  return dp[nums.size()][negasum];
}

int findTargetSumWays(vector<int>& nums, int target) {
  return findTargetDpWay(nums, target);
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 1, 1, 1, 1};
  printf("%d", findTargetSumWays(input, 3));
  return 0;
}
