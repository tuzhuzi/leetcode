#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool isValid(char c, int row, int col, vector<vector<char>> input) {
  for (char z : input[row]) {
    if (z == c) {
      return false;
    }
  }
  for (int i = 0; i < 9; i++) {
    if (input[i][col] == c) {
      return false;
    }
  }
  int rC = row / 3;
  int cC = col / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (input[3 * rC + i][3 * cC + j] == c) {
        return false;
      }
    }
  }
  return true;
}

bool dfs(int count, vector<vector<char>>& input) {
  if (count >= 81) {
    return true;
  }
  int row = count / 9;
  int col = count % 9;
  if (input[row][col] != '.') {
    return dfs(count + 1, input);
  }
  for (char c = '1'; c <= '9'; c++) {
    if (!isValid(c, row, col, input)) {
      continue;
    }
    input[row][col] = c;
    if (dfs(count + 1, input)) {
      return true;
    }
    input[row][col] = '.';
  }
  return false;
}

void solveSudoku(vector<vector<char>>& board) { dfs(0, board); }

int main(int argc, char const* argv[]) {
  vector<vector<char>> input = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  solveSudoku(input);
  for (vector vec : input) {
    printf("%s", string(vec.begin(), vec.end()).c_str());
    printf("\n");
  }
  return 0;
}
