#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
  vector<string> rows(numRows, "");
  bool toDown = true;
  int rowIndex = 0;
  for (char c : s) {
    rows[rowIndex].push_back(c);
    int spaceCount = 0;
    if (toDown) {
      spaceCount = numRows - 2 - rowIndex;
    } else {
      spaceCount = rowIndex - 1;
    }
    if (toDown && rowIndex == numRows - 1) {
      // 向上运动
      toDown = false;
      spaceCount = numRows - 2;
    } else if (!toDown && rowIndex == 0) {
      toDown = true;
      spaceCount = numRows - 2;
    }
    for (int i = 0; i < spaceCount; i++) {
      rows[rowIndex].push_back(' ');
    }
    if (toDown) {
      rowIndex++;
    } else {
      rowIndex--;
    }
  }
  string outPut;
  for (string row : rows) {
    outPut.append(row);
    outPut.push_back('\n');
  }
  return outPut;
}

int main(int argc, char const *argv[]) {
  string input = "PAYPALISHIRING";
  printf("%s", convert(input, 4).c_str());
  return 0;
}
