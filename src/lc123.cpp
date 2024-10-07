#include <cstdio>
#include <vector>

using namespace std;

/**
 * 股票交易问题变形,限制最大交易笔数
 * 贪心思路，找到最大的两个增长区间即可
 * 问题：增长区间非连续，交易区间不能重合
 * 可以假定买卖都可以在同一天，这一天的收入必然是0，可以被最大收益过滤掉
 */
int maxProfit(vector<int>& prices) {
  int buy_1 = -prices[0];
  int sell_1 = 0;
  int buy_2 = -prices[0];
  int sell_2 = 0;
  // 显然有
  // buy_1[i] = max{buy_1[i - 1], - prices[i]}
  // sell_1[i] = max{sell_1[i - 1], prices[i] + buy_1[i]}
  // buy_2[i] = max{buy_2[i - 1], sell_1[i] - prices[i]}
  // sell_2[i] = max{sell_2[i - 1], buy_2[i] + prices[i]}

  for (int i = 1; i < prices.size(); i++) {
    buy_1 = max(buy_1, -prices[i]);
    sell_1 = max(sell_1, buy_1 + prices[i]);
    buy_2 = max(buy_2, sell_1 - prices[i]);
    sell_2 = max(sell_2, buy_2 + prices[i]);
  }
  // 仅一次交易时， sell_2的值和sell_1相同
  return sell_2;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3, 4, 5};
  printf("%d", maxProfit(input));
  return 0;
}
