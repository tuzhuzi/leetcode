#include <cstdio>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int r = 0;
  int c = 0;
  // 这里应该按对角线旋转90度， 已经晕了
  while (r <= (row + 1)/2) {
    for (int c = 0; c < row; c++) {
      int x = c - row/2;
      int y = r - row/2;
      int rotateC = row/2 - y;
      int rotateR = x + row/2;
      int temp = matrix[r][c];
      matrix[r][c] = matrix[rotateR][rotateC];
      matrix[rotateC][rotateR] = 0;
    }
    r++;
  }
}

