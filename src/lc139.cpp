#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> dict;
  for (string s : wordDict) {
    dict.insert(s);
  }

  const int word_length = 20;
  vector<bool> dp(s.size() + 1, false);
  dp[0] = true;

  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= word_length && j <= i; j++) {
      string subS = s.substr(i - j, j);
      if (dict.find(subS) == dict.end()) {
        continue;
      }
      dp[i] = dp[i] | dp[i - j];
      if (dp[i]) {
        break;
      }
    }
  }
  return dp[s.size()];
}

int main(int argc, char const* argv[]) {
  vector<string> dict{"apple", "pen"};
  printf("%d", wordBreak("applepenapple", dict));
  return 0;
}
