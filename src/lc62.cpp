#include <cstdio>
#include <vector>

using namespace std;

int dp(int m, int n, vector<vector<int>>& dpArr, int x, int y) {
  if (x < 0 || x >= m || y < 0 || y >= n) {
    return 0;
  }
  if (dpArr[x][y] >= 0) {
    return dpArr[x][y];
  }
  dpArr[x][y] = dp(m, n, dpArr, x - 1, y) + dp(m, n, dpArr, x, y - 1);
  return dpArr[x][y];
}

int uniquePaths(int m, int n) {
  vector<vector<int>> arr(m, vector<int>(n, -1));
  arr[0][0] = 1;
  return dp(m, n, arr, m - 1, n - 1);
}

int main(int argc, char const* argv[]) {
  printf("%d", uniquePaths(3, 7));
  return 0;
}
