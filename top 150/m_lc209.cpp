#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

/**
 * 和超过target的最短子数组
 * 滑动窗口
 */
int minSubArrayLen(int target, vector<int>& nums) {
  int start = 0;
  int end = 0;
  int minSize = INT_MAX;
  int sum = 0;
  while (end < nums.size()) {
    sum += nums[end];
    while (sum >= target) {
      minSize = min(minSize, end - start + 1);
      sum-= nums[start++];
    }
    end++;
  }
  return minSize;
}

int main(int argc, char const* argv[]) {
  vector<int> input{2, 3, 1, 2, 4, 3};
  printf("%d", minSubArrayLen(7, input));
  return 0;
}
