#include <cstdio>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
  int count = nums[0];
  int index = 0;
  while (index < nums.size() && count < (nums.size() - 1)) {
    int nextStep;
    int tempCount = 0;
    for (int i = 0; i < nums[index] && i < (nums.size() - index); i++) {
      tempCount = i + index + nums[i + index];
      if (tempCount > count) {
        count = tempCount;
        nextStep = i + index;
      }
    }
    if (nextStep <= index) {
      return false;
    }
    index = nextStep;
  }
  return true;
}

bool canJump_leetcode(vector<int>& nums) {
  int cover = 0;
  if (nums.size() == 1) return true;  // 只有一个元素，就是能达到
  for (int i = 0; i <= cover; i++) {  // 注意这里是小于等于cover
    cover = max(i + nums[i], cover);
    if (cover >= nums.size() - 1) return true;  // 说明可以覆盖到终点了
  }
  return false;
}
int main(int argc, char const* argv[]) {
  vector<int> input{2, 0};
  printf("%d", canJump(input));
  return 0;
}
