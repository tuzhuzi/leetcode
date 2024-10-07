#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

/**
 * 股票买卖问题2，可以进行多笔交易
 * 贪心解法，计算每一个涨幅周期的收益
 */
int maxProfit(vector<int>& prices) {
  int lastVal = prices[0];
  int profit = 0;
  for (int i = 1; i < prices.size(); i++) {
    int price = prices[i];
    if (price > lastVal) {
      profit += price - lastVal;
    }
    lastVal = price;
  }
  return profit;
}

/**
 * 定义dp[i][0]是第i天持股的最大收益
 * dp[i][1]是不持股的最大收益
 * // 这里真的对吗，持股状态需要考虑最大收益吗
 * // 逻辑上走的通吗
 * 有 dp[i][0] = max{dp[i - 1][0], dp[i - 1][1] - prices[i]}
 * dp[i][1] = max{dp[i - 1][1], dp[i - 1][0] + prices[0]}
 * 显然有这个状态只和前一天的状态有关，因此dp可以简化为两个状态
 */
int maxProfix_dp(vector<int>& prices) {
  int holdStock = - prices[0];
  int noStock = 0;
  for (int i = 1; i < prices.size(); i ++) {
    int tempHoldStock = max(holdStock, noStock - prices[i]);
    noStock = max(noStock, holdStock + prices[i]);
    holdStock = tempHoldStock;
  }
  // 最后一天一定是不持股
  return noStock;
}