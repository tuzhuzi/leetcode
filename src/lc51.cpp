#include <string>
#include <vector>

using namespace std;

void dumpPath(int n, vector<vector<int>> input,
              vector<vector<string>>& output) {
  for (auto vec : input) {
    vector<string> tempOut;
    for (int val : vec) {
      string s(n, '.');
      s[val] = 'Q';
      tempOut.push_back(s);
    }
    output.push_back(tempOut);
  }
}

void solveNQueens(int n, int rowIndex, vector<int>& path,
                  vector<vector<int>>& output, bool* col, bool* diag,
                  bool* revertDiag) {
  if (rowIndex == n) {
    output.push_back(vector<int>(path));
    return;
  }
  for (int colIndex = 0; colIndex < n; colIndex++) {
    int diagIndex = n + colIndex - rowIndex;
    int revertDiagIndex = colIndex + rowIndex;
    if (col[colIndex] || diag[diagIndex] || revertDiag[revertDiagIndex]) {
      continue;
    }
    col[colIndex] = true;
    diag[diagIndex] = true;
    revertDiag[revertDiagIndex] = true;
    path.push_back(colIndex);
    solveNQueens(n, rowIndex + 1, path, output, col, diag, revertDiag);
    path.pop_back();
    col[colIndex] = false;
    diag[diagIndex] = false;
    revertDiag[revertDiagIndex] = false;
  }
}

vector<vector<string>> solveNQueens(int n) {
  bool col[n];
  bool diag[2 * n];
  bool revertDiag[2 * n];
  for (int i = 0; i < n; i++) {
    col[i] = false;
    diag[2 * i] = false;
    diag[2 * i + 1] = false;
    revertDiag[2 * i] = false;
    revertDiag[2 * i + 1] = false;
  }
  vector<int> path;
  vector<vector<int>> output;
  solveNQueens(n, 0, path, output, col, diag, revertDiag);
  vector<vector<string>> strOut;
  dumpPath(n, output, strOut);
  return strOut;
}

int main(int argc, char const* argv[]) {
  auto output = solveNQueens(2);
  for (vector<string> vec : output) {
    for (string s : vec) {
      printf("%s\n", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
