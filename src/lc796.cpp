#include <cstdio>
#include <vector>

using namespace std;

int dp(int n, vector<int>& arr) {
  if (arr[n] >= 0) {
    return arr[n];
  }
  int sum = 0;
  for (int i = 0; i <= n - 1; i++) {
    sum += dp(i, arr) * dp(n - 1 - i, arr);
  }
  arr[n] = sum;
  return sum;
}

int numTrees(int n) {
  vector<int> arr(n + 1, -1);
  arr[0] = 1;
  arr[1] = 1;
  return dp(n, arr);
}

int main(int argc, char const* argv[]) {
  printf("%d", numTrees(3));
  return 0;
}
