#include <cstdio>
#include <vector>

using namespace std;

/**
 * 股票交易，最多k次交易
 */
int maxProfit(vector<int>& prices, int k) {
  // dp[i][0] 第k次交易时买入后的收益
  // do[i][1] 第k次交易时，卖出后的收益
  // 显然有 dp[i][0] = max{dp[i][0], dp[i - 1][1] - prices[i]}
  // dp[i][1] = max{dp[i][1], dp[i][0] + prices[i]}
  vector<vector<int>> dp(k + 1, vector<int>(2, 0));
  for (auto& v : dp) {
    v[0] = -prices[0];
  }
  for (int i = 1; i < prices.size(); i++) {
    for (int j = 1; j <= k; j++) {
      dp[j][0] = max(dp[j][0], dp[j - 1][1] - prices[i]);
      dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
    }
  }
  return dp[k][1];
}

int main(int argc, char const* argv[]) {
  vector<int> prices{3, 2, 6, 5, 0, 3};
  printf("%d", maxProfit(prices, 7));
  return 0;
}
