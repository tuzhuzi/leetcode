#include <cstdio>
#include <vector>

using namespace std;

/**
 * 三角形路径和，显而易见的动态规划题
 * https://leetcode.cn/problems/triangle/?envType=study-plan-v2&envId=top-interview-150
 */
int minimumTotal(vector<vector<int>>& triangle) {
  // dp[i][n]代表三角形第i层，第n个元素的最大路径和
  // 显然有dp[i + 1][n] = max(dp[i - 1][n], dp[i - 1][n + 1]) + tri[i + 1][n]
  // 既然只与上一层的值有关，那自然是可以使用滚动数组处理的
  vector<int> dp(triangle.size(), __INT_MAX__);
  int minPath = __INT_MAX__;
  dp[0] = triangle[0][0];
  for (int i = 1; i < triangle.size(); i++) {
    for (int j = i; j >= 0; j--) {
      int tempVal = dp[j];
      if (j > 0) {
        dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
      } else {
        dp[j] = dp[j] + triangle[i][j];
      }
    }
  }
  for (int i = 0; i < triangle.size(); i++) {
    minPath = min(dp[i], minPath);
  }
  return minPath;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  printf("%d", minimumTotal(triangle));
  return 0;
}
