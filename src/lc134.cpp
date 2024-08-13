#include <cstdio>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  vector<int> profile(gas.size());
  int maxLoss = 0;
  int maxLossIndex = 0;
  int lossSum = 0;
  for (int i = 0; i < gas.size(); i++) {
    profile[i] = gas[i] - cost[i];
    lossSum += profile[i];
    if (lossSum < maxLoss) {
      maxLoss = lossSum;
      maxLossIndex = i;
    }
  }
  if (lossSum < 0) {
    return -1;
  }
  return (maxLossIndex + 1) % gas.size();
}

int main(int argc, char const* argv[]) {
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};
  printf("%d", canCompleteCircuit(gas, cost));
  return 0;
}
