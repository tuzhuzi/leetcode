#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

/**
 * 用动态规划的思路来做, 找到最接近一半重量的石头
 * dp[i]代表最大容量为i的背包，可以装下的石头重量
 * 显而易见有dp[j] = max{dp[j], dp[j - stone[i]] + stone[i]}
 * 所求目标即为dp[sum/2]
 */
int lastStoneWeightII(vector<int>& stones) {
  int sum = 0;
  for (int& stone : stones) {
    sum += stone;
  }
  int target = sum / 2;
  vector<int> dp(target + 1, 0);
  for (int i = 0; i < stones.size(); i++) {
    for (int j = target; j >= 0; j--) {
      if (j >= stones[i]) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
  }
  return sum - dp[target] * 2;
}

int main(int argc, char const* argv[]) {
  vector<int> input{31, 26, 33, 21, 40};
  printf("%d", lastStoneWeightII(input));
  return 0;
}
