#include <cstdio>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums) {
  if (nums.size() <= 1) {
    return nums.size();
  }
  vector<int> sublist;
  sublist.push_back(nums[0]);
  bool lastValue;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == sublist[sublist.size() - 1]) {
      continue;
    }
    bool newValue = nums[i] > sublist[sublist.size() - 1];
    if (sublist.size() < 2 || newValue != lastValue) {
      sublist.push_back(nums[i]);
    } else if (sublist.size() > 1) {
      // 过度元素， 替换成新的峰或者谷
      sublist[sublist.size() - 1] = nums[i];
    }
    lastValue = newValue;
  }
  return sublist.size();
}

int main(int argc, char const* argv[]) {
  vector<int> input{33, 53, 12, 64, 50, 41, 45, 21, 97, 35, 47, 92,  39, 0,  93,
                    55, 40, 46, 69, 42, 6,  95, 51, 68, 72, 9,  32,  84, 34, 64,
                    6,  2,  26, 98, 3,  43, 30, 60, 3,  68, 82, 9,   97, 19, 27,
                    98, 99, 4,  30, 96, 37, 9,  78, 43, 64, 4,  65,  30, 84, 90,
                    87, 64, 18, 50, 60, 1,  40, 32, 48, 50, 76, 100, 57, 29, 63,
                    53, 46, 57, 93, 98, 42, 80, 82, 9,  41, 55, 69,  84, 82, 79,
                    30, 79, 18, 97, 67, 23, 52, 38, 74, 15};
  printf("%d", wiggleMaxLength(input));
  return 0;
}
