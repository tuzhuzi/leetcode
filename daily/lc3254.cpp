#include <cstdio>
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-i/
 * 职业感觉，应该用dp数组来处理
 */
vector<int> resultsArray(vector<int>& nums, int k) {
  // 定义dp[i][j] 是从i开始，连续j个数的最大能量值
  // 显然有dp[i][1] = nums[i]
  // dp[i][j] = dp[i][j - 1] > 1 && num[i + j - 1] > num[i + j - 2] ? num[i + j
  // - 1] : -1
  // dp法的复杂度是O(nk)
  vector<int> dp(nums.size(), 0);
  for (int i = 0; i < nums.size(); i++) {
    dp[i] = nums[i];
  }
  for (int j = 2; j <= k; j++) {
    for (int i = 0; i <= nums.size() - j; i++) {
      if (dp[i] < 0 || nums[i + j - 1] != nums[i + j - 2] + 1) {
        dp[i] = -1;
      } else {
        dp[i] = nums[i + j - 1];
      }
    }
  }
  vector<int> ret(dp.begin(), dp.end() - k + 1);
  return ret;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3, 4, 3, 2, 5};
  for (int val : resultsArray(input, 3)) {
    printf("%d ", val);
  }
  return 0;
}
