#include <vector>
using namespace std;

/**
 * https://leetcode.cn/problems/special-array-i/description/
 * 数组相邻元素奇偶性问题
 */

bool isArraySpecial(vector<int>& nums) {
  if (nums.empty()) {
    return false;
  }
  bool isOdd = nums[0] % 2 == 0;
  for (int i = 1; i < nums.size(); i++) {
    bool newOdd = nums[i] % 2 == 0;
    if (newOdd == isOdd) {
      return false;
    }
    isOdd = newOdd;
  }
  return true;
}