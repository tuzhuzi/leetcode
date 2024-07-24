#include <string>
using namespace std;

void revertStr(char* s, int begin, int end) {
  for (int i = begin; i < (begin + end + 1) / 2; i++) {
    char c = s[i];
    s[i] = s[begin + end - i];
    s[begin + end - i] = c;
  }
}

string revertStr(string s, int k) {
  char* cArr = s.data();
  int i = 0;
  while (i < s.size()) {
    int end = i + k - 1;
    if (end >= s.size()) {
      end = s.size() - 1;
    }
    revertStr(cArr, i, end);
    i = end + 1 + k;
  }
  return string(cArr);
}

int main(int argc, char const* argv[]) {
  string s = "ninjaslayer";
  string revertS = revertStr(s, 3);
  printf("%s", revertS.c_str());
  return 0;
}
