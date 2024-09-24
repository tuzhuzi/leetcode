#include <cmath>
#include <cstdio>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

long long maximumSubsequenceCount(string text, string pattern) {
  vector<long long> p1Count;
  int p2Count = 0;
  for (char c : text) {
    if (c == pattern[0]) {
      p1Count.push_back(0);
    } else if (c == pattern[1]) {
      p2Count++;
      for (long long& v : p1Count) {
        v++;
      }
    }
  }
  long long count = accumulate(p1Count.begin(), p1Count.end(), 0);
  // 最有效率低两种方式，把p[0]拼在字符串第一个，增加p2Count的数量
  // 把p[1]拼在字符串末尾，增加p1Count的数量
  return count + p1Count.size() > p2Count ? p1Count.size() : p2Count;
}

int main(int argc, char const* argv[]) {
  printf("%lld", maximumSubsequenceCount("abdcdbc", "ab"));
  return 0;
}
