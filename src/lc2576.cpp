#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int maxNumOfMarkedIndices(vector<int>& nums) {
  vector<bool> mark(nums.size(), false);
  sort(nums.begin(), nums.end());
  int count = 0;
  int right = nums.size() - 1;
  // left的起点很重要，最多匹配size/2对，所以left从中间开始即可
  int left = nums.size() / 2 - 1;
  while (right >= 0 && left >= 0) {
    while (left >= 0 && (mark[left] || nums[left] > nums[right] / 2)) {
      left--;
    }
    if (left < 0) {
      break;
    }
    count += 2;
    mark[left] = true;
    mark[right] = true;
    while (mark[right] && right >= 0) {
      right--;
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  vector<int> input{42, 83, 48, 10, 24, 55, 9,  100, 10, 17, 17, 99, 51,
                    32, 16, 98, 99, 31, 28, 68, 71,  14, 64, 29, 15, 40};
  printf("%d", maxNumOfMarkedIndices(input));
  return 0;
}
