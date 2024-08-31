#include <cstdio>
#include <vector>

using namespace std;

int dp(int n, vector<int>& arr, bool needSplit) {
  if (arr[n] > 0) {
    return arr[n];
  }
  if (n == 1) {
    arr[n] = 1;
    return arr[n];
  }
  int tempVal = 1;
  if (!needSplit) {
    tempVal = n;
  }
  for (int i = 1; i <= n / 2; i++) {
    int val = dp(i, arr, false) * dp(n - i, arr, false);
    if (val > tempVal) {
      tempVal = val;
    }
  }
  arr[n] = tempVal;
  return tempVal;
}

int integerBreak(int n) {
  vector<int> arr(n + 1, 0);
  int val = dp(n, arr, true);
  return val;
}

int main(int argc, char const* argv[]) {
  printf("%d", integerBreak(10));
  return 0;
}
