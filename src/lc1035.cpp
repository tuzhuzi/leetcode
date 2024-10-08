#include <cstdio>
#include <vector>

using namespace std;

/**
 * 相同数字的不重合线，其实和公共子数组规则一样
 * 定义dp[i][j]是截至nums1[i], nums2[j]的最多子数组
 * 显然有dp[i][j] = dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1])
 */
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
  vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[nums1.size()][nums2.size()];
}

int main(int argc, char const* argv[]) {
  vector<int> nums1{1, 2, 4};
  vector<int> nums2{1, 4, 2};
  printf("%d", maxUncrossedLines(nums1, nums2));
  return 0;
}
