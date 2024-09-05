#include <cstdio>
#include <vector>

using namespace std;

void dfs(int startIndex, vector<int>& coins, int& count, int total,
         int amount) {
  if (total == amount) {
    count++;
    return;
  }
  if (total > amount) {
    return;
  }
  for (int i = startIndex; i < coins.size(); i++) {
    dfs(i, coins, count, total + coins[i], amount);
  }
}

int dpWay(int amount, vector<int>& coins) {
  vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
  // 初值
  for (int i = 0; i <= coins.size(); i++) {
    // 任意组合成0的方式，都起码是1种
    dp[i][0] = 1;
  }
  for (int i = 1; i <= coins.size(); i++) {
    for (int j = 1; j <= amount; j++) {
      int temp = j;
      while (temp >= 0) {
        dp[i][j] += dp[i - 1][temp];
        temp -= coins[i - 1];
      }
    }
  }
  return dp[coins.size()][amount];
}

int dpWayBetter(int amount, vector<int>& coins) {
  // 用滚动数组优化掉一个维度
  vector<int> dp(amount + 1, 0);
  dp[0] = 1;
  for (int coin : coins) {
    for (int i = coin; i <= amount; i++) {
      // 实际上等于上一步的dp[i][j]+=dp[i-1][temp]
      dp[i] += dp[i - coin];
    }
  }
  return dp[amount];
}

int change(int amount, vector<int>& coins) {
  return dpWayBetter(amount, coins);
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 5};
  printf("%d", change(5, input));
  return 0;
}
