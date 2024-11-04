#include <cmath>
#include <cstdio>

bool judgeSquareSum(int c) {
  int max = (int)sqrt(c);
  int left = 1;
  int right = max;
  while (left <= right) {
    int sum = left*left + right*right;
    if (sum == c) {
      printf("%d %d\n", left, right);
      return true;
    }
    if (sum < c) {
      left++;
    } else {
      right--;
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
  judgeSquareSum(17);
  return 0;
}
