#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
  // 贪心思路，首先先起始位置排序，然后尽量晚的在重合位置开枪
  sort(points.begin(), points.end());
  // 然后开始找位置开枪
  int arrowCount = 0;
  int i = 0;
  while (i < points.size()) {
    // 最晚的射出位置
    int maxEnd = points[i][1];
    int j = i + 1;
    // 找到重合的气球
    while (j < points.size() && points[j][0] <= maxEnd) {
      maxEnd = min(maxEnd, points[j][1]);
      j++;
    }
    i = j;
    arrowCount++;
  }
  return arrowCount;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> points{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  printf("%d ", findMinArrowShots(points));
  return 0;
}
