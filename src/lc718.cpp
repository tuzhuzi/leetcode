#include <cstdio>
#include <vector>

using namespace std;

/**
 * 最长公共子字符串
 * dp[i][j] 代表从nums1[i:]和nums2[j:]开始的公共字符串的长度
 * 显然有 dp[i][j] = nums1[i] == nums2[j] ?dp[i - 1][j - 1] + 1 : 0;
 */
int findLength(vector<int>& nums1, vector<int>& nums2) {
  int maxLength = 0;
  vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        maxLength = max(maxLength, dp[i][j]);
      }
    }
  }
  return maxLength;
}

int main(int argc, char const* argv[]) {
  vector<int> nums1{3, 2, 1, 4, 7};
  vector<int> nums2{1, 2, 3, 2, 1};
  printf("%d", findLength(nums1, nums2));
  return 0;
}
