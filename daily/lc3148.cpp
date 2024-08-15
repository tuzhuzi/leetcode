#include <cstdio>
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/maximum-difference-score-in-a-grid/
 * 初步设想是用动态规划处理
 * dp[x, y]代表子矩阵[(x:row-1), (y:col-1)]的最大值
 * maxScore = dp[x, y ] - grid[x, y]
 */

int findDp(vector<vector<int>>& grid, vector<vector<int>>& dp, int x, int y,
           int& maxScore) {
  if (x >= grid.size() || y >= grid[0].size()) {
    return 0;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  int val = max(findDp(grid, dp, x + 1, y, maxScore),
                findDp(grid, dp, x, y + 1, maxScore));
  if (val - grid[x][y] > maxScore) {
    maxScore = val - grid[x][y];
  }
  dp[x][y] = max(grid[x][y], val);
  return val;
}
int maxScore(vector<vector<int>>& grid) {
  vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
  int maxScore = -__INT_MAX__;
  findDp(grid, dp, 0, 0, maxScore);
  return maxScore;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid{
      {9, 5, 7, 3}, {8, 9, 6, 1}, {9, 7, 14, 3}, {2, 5, 3, 1}};
  printf("%d", maxScore(grid));
  return 0;
}
