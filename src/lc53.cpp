#include <cstdio>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
  int tempSum = 0;
  int maxSum = -__INT_MAX__;
  for (int i = 0; i < nums.size(); i++) {
    tempSum += nums[i];
    if (tempSum > maxSum) {
      maxSum = tempSum;
    }
    if (tempSum < 0) {
      tempSum = 0;
    }
  }
  return maxSum;
}

int main(int argc, char const* argv[]) {
  vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  printf("%d", maxSubArray(input));
  return 0;
}
