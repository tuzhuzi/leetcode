#include <cstdio>
#include <vector>

using namespace std;

int findDp(vector<int>& cost, int n, vector<int>& dp) {
  if (dp[n] > 0) {
    return dp[n];
  }
  if (n <= 1) {
    dp[n] = 0;
    return dp[n];
  }
  dp[n] = min(findDp(cost, n - 1, dp) + cost[n - 1],
              findDp(cost, n - 2, dp) + cost[n - 2]);
  return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
  vector<int> dp(cost.size() + 1, 0);
  return findDp(cost, cost.size(), dp);
}

int main(int argc, char const* argv[]) {
  vector<int> input{10, 15, 20};
  printf("%d ", minCostClimbingStairs(input));
  return 0;
}
