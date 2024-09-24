#include <cstdio>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string add(string left, string right) {
  deque<char> q;
  int index = 0;
  int hasLeft = 0;
  while (index < left.size() || index < right.size()) {
    int leftC = index < left.size() ? left[left.size() - 1 - index] - '0' : 0;
    int rightC =
        index < right.size() ? right[right.size() - 1 - index] - '0' : 0;
    q.push_back((leftC + rightC + hasLeft) % 10 + '0');
    if (leftC + rightC >= 10) {
      hasLeft = 1;
    } else {
      hasLeft = 0;
    }
    index++;
  }
  if (hasLeft > 0) {
    q.push_back(hasLeft + '0');
  }

  vector<char> output;
  while (!q.empty()) {
    output.push_back(q.back());
    q.pop_back();
  }
  return string(output.begin(), output.end());
}

int main(int argc, char const *argv[]) {
  printf("%s", add("123", "97").c_str());
  return 0;
}
