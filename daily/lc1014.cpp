#include <cstdio>
#include <vector>

using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
  // 两个点的收益 v = value[i] + value[j] - (j - i)
  // 可以优化为 v= value[j] - j + value[i] + i
  // 我还是感觉有一点问题，显然应该有n^2个值之间的遍历，为什么这里只剩下n了呢
  int value = 0;
  int vi = values[0];
  for (int i = 1; i < values.size(); i++) {
    value = max(value, vi + values[i] - i);
    vi = max(vi, values[i] + i);
  }
  return value;
}

int main(int argc, char const* argv[]) {
  vector<int> input{8, 1, 5, 2, 6};
  printf("%d", maxScoreSightseeingPair(input));
  return 0;
}
