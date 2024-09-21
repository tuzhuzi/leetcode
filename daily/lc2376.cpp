#include <cstdio>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> memo;

int dp(int mask, bool prefixSmaller, const string& nStr) {
  if (__builtin_popcount(mask) == nStr.size()) {
    return 1;
  }
  int key = mask * 2 + (prefixSmaller ? 1 : 0);
  if (!memo.count(key)) {
    int res = 0;
    int lowerBound = mask == 0 ? 1 : 0;
    int upperBound = prefixSmaller ? 9 : nStr[__builtin_popcount(mask)] - '0';
    for (int i = lowerBound; i <= upperBound; i++) {
      if (((mask >> i) & 1) == 0) {
        res += dp(mask | (1 << i), prefixSmaller || i < upperBound, nStr);
      }
    }
    memo[key] = res;
  }
  return memo[key];
}

int countSpecialNumbers_LEETCODE_STANDART(int n) {
  string nStr = to_string(n);
  int res = 0;
  int prod = 9;
  for (int i = 0; i < nStr.size() - 1; i++) {
    res += prod;
    prod *= 9 - i;
  }
  res += dp(0, false, nStr);
  return res;
}

int calcCompose(int m, int n) {
  if (n > m) {
    return 0;
  }
  int count = 1;
  for (int i = 0; i < n; i++) {
    count *= (m - i);
  }
  return count;
}

int countSpecialNumbers(int n) {
  // 先计算位数小于n的
  string strN = to_string(n);
  int count = 0;
  for (int i = 1; i <= strN.size() - 1; i++) {
    // 计算i位数中符合需求的数量
    // 第一位固定不为0， 剩下的位数从除第一位以外的数中排列组合
    count += 9 * calcCompose(9, i - 1);
  }

  // 计算位数和n相同， 但小于n的情况
  vector<bool> mark(10, false);
  for (int i = 0; i < strN.size() && i < 10; i++) {
    int c = strN[i] - '0';
    // 低于i位数的排列组合
    int composeCount = calcCompose(10 - i - 1, strN.size() - 1 - i);
    for (int j = 0; j < c; j++) {
      if (mark[j]) {
        continue;
      }
      // 第一位不能为0， 或者说为0的情况已经考虑过了
      if (j == 0 && i == 0) {
        continue;
      }
      count += composeCount;
    }
    // 这一位已经和前面重合了，不需要剩下的计算了
    if (mark[c]) {
      break;
    }
    mark[c] = true;
  }
  // 最后再来考虑n本身是否满足要求
  mark = vector<bool>(10, false);
  bool needAddOne = true;
  for (char c : strN) {
    int i = c - '0';
    if (mark[i]) {
      needAddOne = false;
      break;
    }
    mark[i] = true;
  }
  return count + needAddOne;
}

int main(int argc, char const* argv[]) {
  printf("%d", countSpecialNumbers(1581));
  return 0;
}
