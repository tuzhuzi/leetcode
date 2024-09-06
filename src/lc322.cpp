#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
  // dp[i], 支付i时，最少的硬币组合
  // 初值即为dp[0] = 0;
  // 转移方程 dp[j] = min(dp[j], dp[j - num] + 1)
  // dp[j] = -1代表不可能的硬币组合
  vector<int> dp(amount + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
      if (i < coin || dp[i - coin] == -1) {
        continue;
      }
      dp[i] = dp[i] < 0 ? dp[i - coin] + 1 : min(dp[i], dp[i - coin] + 1);
    }
  }
  if (dp[amount] == -1) {
    return 0;
  }
  return dp[amount];
}

int main(int argc, char const* argv[]) {
  vector<int> coins{1, 2, 5};
  printf("%d", coinChange(coins, 11));
  return 0;
}
