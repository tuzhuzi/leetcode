#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

/**
 * 注意，dfs算法的复杂度时2^n，复杂度太高了
 */
bool dfs(int index, int checkSum, int tempSum, vector<int>& nums) {
  if (tempSum == checkSum) {
    return true;
  }
  if (tempSum > checkSum) {
    return false;
  }
  for (int i = index; i < nums.size(); i++) {
    if (dfs(i + 1, checkSum, tempSum + nums[i], nums)) {
      return true;
    }
  }
  return false;
}

/**
 * 利用动态规划解题
 */
bool dynamicPartision(vector<int>& nums, int checkSum) {
  // dp[i][j]代表前i个数中，是否可以凑出和为j的组合
  vector<vector<bool>> dp(nums.size(), vector<bool>(checkSum + 1, false));

  // 初始化， 显然有dp[i][0] = true, 即不取任何数时，和即为0
  for (auto& v : dp) {
    v[0] = true;
  }
  dp[0][nums[0]] = true;
  // dp转移方程 dp[i][j] = dp[i - 1][j - nums[i]] | dp[i - 1][j]
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= checkSum; j++) {
      if (nums[i] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
      }
    }
  }
  return dp[nums.size() - 1][checkSum];
}

bool canPartition(vector<int>& nums) {
  int sum = 0;
  for (int& num : nums) {
    sum += num;
  }
  if (sum % 2 != 0) {
    return false;
  }
  return dynamicPartision(nums, sum / 2);
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 5};
  printf("%d", canPartition(input));
  return 0;
}
