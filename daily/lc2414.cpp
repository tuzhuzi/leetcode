#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int longestContinuousSubstring(string s) {
  vector<char> vec;
  int maxSize = 0;
  for (char c : s) {
    if (vec.empty() || c - vec[vec.size() - 1] == 1) {
      vec.push_back(c);
      continue;
    }
    if (vec.size() > maxSize) {
      maxSize = vec.size();
    }
    vec.clear();
    vec.push_back(c);
  }
  if (vec.size() > maxSize) {
    maxSize = vec.size();
  }
  return maxSize;
}

int main(int argc, char const *argv[]) {
  string s = "abcde";
  printf("%d", longestContinuousSubstring(s));
  return 0;
}
