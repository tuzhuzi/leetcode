#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

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