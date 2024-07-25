#include <cstdio>
#include <iostream>
using namespace std;

/**
 * https://kamacoder.com/problempage.php?pid=1065
 */
string rightRotateString(string s, int k) {
  char* cArr = s.data();
  char tempcArr[s.size()];
  for (int i = 0; i < s.size(); i++) {
    int rotateIndex = (i + k) % s.size();
    tempcArr[rotateIndex] = cArr[i];
  }
  return string(tempcArr, tempcArr + s.size());
}

int main(int argc, char const* argv[]) {
  string input = "abcdefg";
  printf("%s", rightRotateString(input, 2).c_str());
  return 0;
}
