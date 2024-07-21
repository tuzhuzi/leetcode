#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

void splitInteger(int input, vector<int>& out) {
  if (input < 10) {
    out.push_back(input);
    return;
  }
  out.push_back(input % 10);
  splitInteger(input / 10, out);
}

int genNewValue(vector<int> input) {
  int out = 0;
  for (int num : input) {
    out += pow(num, 2);
  }
  return out;
}

bool isHappy(int num) {
  unordered_set<int> set;
  vector<int> temp;
  int tempNum = num;
  while (set.find(tempNum) == set.end()) {
    set.insert(tempNum);
    temp.clear();
    splitInteger(tempNum, temp);
    tempNum = genNewValue(temp);
    if (tempNum == 1) {
      return true;
    }
  }
  return false;
}

int main(int argc, char const* argv[]) {
  int test = 19;
  printf("isHappy: %d", isHappy(test));
  return 0;
}
