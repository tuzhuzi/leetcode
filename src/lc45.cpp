#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
  vector<int> stack;
  if (nums.empty()) {
    return 0;
  }
  stack.push_back(0);
  while (stack.back() + nums[stack.back()] < (nums.size() - 1)) {
    int nextStep = 0;
    int maxLength = 0;
    int step = nums[stack.back()];
    if (step == 0) {
      return 0;
    }
    for (int i = 1; i <= step; i++) {
      int index = stack.back() + i;
      int length = nums[index] + index;
      if (length > maxLength) {
        maxLength = length;
        nextStep = index;
      }
    }
    stack.push_back(nextStep);
  }

  return stack.size();
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3};
  printf("%d ", jump(input));
  return 0;
}
