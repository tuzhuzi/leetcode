#include <vector>
#include <cstdio>

using namespace std;

/**
 * 包含冷冻期的股票交易策略
 * 换汤不换药, 定义dp[i][0]是第i天买入股票， dp[i][1]是第i天卖出股票，易有
 * dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i])
 * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
 */
int maxProfit(vector<int>& prices) {
   vector<vector<int>> dp(prices.size() + 1,  vector<int>{-prices[0], 0});
   for (int i = 1; i <= prices.size(); i++) {
     dp[i][0] = max(dp[i - 1][0], i >= 2 ? dp[i - 2][1] - prices[i - 1]:-prices[i - 1]);
     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);
   }
   return dp[prices.size()][1];
}