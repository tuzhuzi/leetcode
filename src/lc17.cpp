#include <string>
#include <vector>
using namespace std;

string map[]{"abc", "edf", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(string digit, int startIndex, string& path, vector<string>& output) {
  if (path.size() == digit.size()) {
    output.push_back(string(path));
    return;
  }
  for (int i = startIndex; i < digit.size(); i++) {
    char d = digit[i];
    for (char s : map[d - '2']) {
      path.push_back(s);
      dfs(digit, i + 1, path, output);
      path.pop_back();
    }
  }
}

vector<string> letterCombinations(string digits) {
  string path;
  vector<string> output;
  dfs(digits, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<string> output = letterCombinations("2234");
  for (string s : output) {
    printf("%s ", s.c_str());
  }
  return 0;
}
