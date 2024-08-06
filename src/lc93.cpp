#include <string>
#include <vector>

using namespace std;

int getValidInteger(string s) {
  if (s.size() > 1 && s[0] == '0') {
    return -1;
  }
  return stoi(s);
}

void dfs(string input, int index, vector<int>& path, vector<string>& output) {
  if (path.size() == 4 && index >= input.size()) {
    string s;
    for (int val : path) {
      s.append(to_string(val));
      s.push_back(':');
    }
    s.pop_back();
    output.push_back(s);
    return;
  }
  if (path.size() > 4) {
    return;
  }
  string s;
  for (int i = index; i < input.size(); i++) {
    s.push_back(input[i]);
    int val = getValidInteger(s);
    if (val < 0 || val > 255) {
      break;
    }
    path.push_back(val);
    dfs(input, i + 1, path, output);
    path.pop_back();
  }
}

vector<string> restoreIpAddresses(string s) {
  vector<int> path;
  vector<string> output;
  dfs(s, 0, path, output);
  return output;
}

int main(int argc, char const* argv[]) {
  vector<string> split = restoreIpAddresses("101023");
  for (string s : split) {
    printf("%s\n", s.c_str());
  }
  return 0;
}
