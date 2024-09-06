#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int numSquares(int n) {
  vector<int> dp(n + 1, n);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sqrt(i); j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  return dp[n];
}

int main(int argc, char const *argv[]) {
  printf("%d", numSquares(13));
  return 0;
}
