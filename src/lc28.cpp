#include <string>
using namespace std;

bool compareString(char* c1, int c1Begin, int c1End, char* c2, int length) {
  int c1Length = (c1End - c1Begin) + 1;
  if (c1Length < length) {
    return false;
  }
  for (int i = 0; i < length; i++) {
    if (c1[c1Begin + i] != c2[i]) {
      return false;
    }
  }
  return true;
}

int strStr(string hyStack, string needle) {
  char* stackC = hyStack.data();
  char* needleC = needle.data();
  int stackLength = hyStack.size();
  int needleLength = needle.size();
  for (int i = 0; i <= (stackLength - needleLength); i++) {
    if (compareString(stackC, i, stackLength - 1, needleC, needleLength)) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char const* argv[]) {
  string hyStack = "sadOutsad";
  string needle = "sad";
  printf("%d", strStr(hyStack, needle));
  return 0;
}
