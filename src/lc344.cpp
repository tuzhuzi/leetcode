#include <cstdio>
#include <vector>

using namespace std;

/**
 * 利用O(1)的空间复杂度，反转字符串
 */
void revertString(vector<char>& s) {
  for (int i = 0; i < s.size() / 2; i++) {
    char temp = s[i];
    s[i] = s[s.size() - i - 1];
    s[s.size() - i - 1] = temp;
  }
}

void revertString_doublePointer(vector<char>& s) {
  int begin = 0;
  int end = s.size() - 1;
  while (begin < end) {
    char temp = s[begin];
    s[begin] = s[end];
    s[end] = temp;
    begin++;
    end--;
  }
}

int main(int argc, char const* argv[]) {
  vector<char> s = {'n', 'i', 'j', 'a', 's', 'l', 'a', 'y', 'e', 'r'};
  revertString_doublePointer(s);
  for (char c : s) {
    printf("%c ", c);
  }
  return 0;
}
