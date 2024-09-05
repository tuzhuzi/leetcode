#include <iostream>
#include <queue>
#include <string>

using namespace std;

string clearDigits(string s) {
  deque<char> q;
  for (char c : s) {
    if (isdigit(c) && !q.empty()) {
      q.pop_back();
      continue;
    }
    q.push_back(c);
  }
  return string(q.begin(), q.end());
}

int main(int argc, char const *argv[]) {
  string c;
  cin >> c;
  cout << clearDigits(c) << endl;
  return 0;
}
