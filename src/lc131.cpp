#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool isCycleString(string s) {
  for (int i = 0; i < (s.size() / 2); i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

void dfs(string s, int startIndex, vector<string>& path,
         vector<vector<string>>& output) {
  if (startIndex == s.size()) {
    output.push_back(vector<string>(path));
    return;
  }
  string tempS;
  for (int i = startIndex; i < s.size(); i++) {
    tempS.push_back(s[i]);
    if (isCycleString(tempS)) {
      path.push_back(tempS);
      dfs(s, i + 1, path, output);
      path.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<string> path;
  vector<vector<string>> output;
  dfs(s, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  auto output = partition("aab");
  for (vector<string> vec : output) {
    for (string s : vec) {
      printf("%s ", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
