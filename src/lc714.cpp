#include <cstdio>
#include <vector>

using namespace std;

/**
 * 包含手续费的交易结算体系
 */
int maxProfit(vector<int>& prices, int fee) {
  int holdStock = -prices[0];
  int noStock = 0;
  for (int i = 1; i < prices.size(); i++) {
    holdStock = max(holdStock, noStock - prices[i]);
    noStock = max(noStock, holdStock + prices[i] - fee);
  }
  return noStock;
}

int main(int argc, char const* argv[]) {
  vector<int> prices{1, 3, 2, 8, 4, 9};
  printf("%d", maxProfit(prices, 2));
  return 0;
}
