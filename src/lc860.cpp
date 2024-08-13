#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
  vector<int> cash(2, 0);
  for (int bill : bills) {
    if (bill == 5) {
      cash[0]++;
    }
    if (bill == 10) {
      if (cash[0] <= 0) {
        return false;
      }
      cash[0]--;
      cash[1]++;
    }
    if (bill == 20) {
      if (cash[1] > 0 && cash[0] > 0) {
        cash[1]--;
        cash[0]--;
      } else if (cash[0] >= 3) {
        cash[0] -= 3;
      } else {
        return false;
      }
    }
  }
  return true;
}