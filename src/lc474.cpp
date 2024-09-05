#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  // 01背包的遍历顺序，先遍历内容
  for (string s : strs) {
    int zeroCount = 0;
    int oneCount = 0;
    for (char c : s) {
      if (c == '0') {
        zeroCount++;
      } else {
        oneCount++;
      }
    }
    // 再遍历容量，容量的遍历倒叙，避免内容被重复添加
    for (int i = m; i >= oneCount; i--) {
      for (int j = n; j >= zeroCount; j--) {
        dp[i][j] = max(dp[i][j], dp[i - oneCount][j - zeroCount] + 1);
      }
    }
  }
  return dp[m][n];
}