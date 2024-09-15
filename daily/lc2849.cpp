#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int numberOfPoints(vector<vector<int>>& nums) {
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a[0] < b[0]; });
  int length = 0;
  int lastPos = -INT_MAX;
  for (vector<int>& num : nums) {
    if (num[1] < lastPos) {
      continue;
    }
    length += num[1] - max(lastPos, num[0]) + 1;
    lastPos = num[1] + 1;
  }
  return length;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> input{{4, 4}, {9, 10}, {3, 8}};
  printf("%d", numberOfPoints(input));
  return 0;
}
