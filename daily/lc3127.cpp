#include <vector>
using namespace std;

bool canMakeSquare(vector<vector<char>>& grid) {
  for (int r = 0; r < grid.size() - 1; r++) {
    for (int c = 0; c < grid[0].size() - 1; c++) {
      int countW = 0;
      int countB = 0;
      for (int i = r; i <= r + 1; i++) {
        for (int j = c; j <= c + 1; j++) {
          if (grid[i][j] == 'W') {
            countW++;
          } else {
            countB++;
          }
        }
      }
      if (countW >= 3 || countB >= 3) {
        return true;
      }
    }
  }
  return false;
}