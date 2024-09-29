#include <cstdio>
#include <string>
#include <vector>


using namespace std;

/**
 * 最长公共子序列
 * https://leetcode.cn/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
 */
int longestCommonSubsequence(string text1, string text2) {
  // dp[0][0] = 0;
  // dp[i][j] = max{dp[i - 1][j], dp[i][j - 1] , dp[i - 1][j - 1]+ text1[i] == text2[j]}
  // 注意这里 dp[i - 1][j - 1]需要倒序访问， dp[i - 1][j]又需要正序访问，所以这里需要用二维数组才行
  vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size()+1, 0));
  for (int i = 1; i <= text1.size(); i++) {
    for (int j = 1; j <= text2.size(); j++) {
      if (text1[i - 1] == text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[text1.size()][text2.size()];
}

int main(int argc, char const *argv[]) {
  string text1 = "aab";
  string text2 = "abab";
  printf("%d", longestCommonSubsequence(text1, text2));
  return 0;
}
