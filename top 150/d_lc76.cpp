#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 包含所有的字符的最小子串
 * https://leetcode.cn/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-interview-150
 */

string minWindow(string s, string t) {
  unordered_map<char, int> record;
  for (char c : t) {
    record[c]++;
  }

  int left = 0;
  int right = 0;
  int length = INT_MAX;
  int minLeft = left;
  int minRight = right;
  while (left < s.size()) {
    if (!record.count(s[left])) {
      left++;
      continue;
    }
    bool find = true;
    for (auto it : record) {
      if (it.second > 0) {
        find = false;
        break;
      }
    }
    if (!find) {
      while (right < s.size()) {
        char c = s[right++];
        if (record.count(c)) {
          record[c]--;
        }
        bool check = true;
        for (auto it : record) {
          if (it.second > 0) {
            check = false;
            break;
          }
        }
        if (check) {
          find = true;
          break;
        }
      }
    }
    // 更新一下最小长度
    if (find && (right - left) < length) {
      minLeft = left;
      minRight = right;
      length = minRight - minLeft;
    }
    // 把left出栈
    record[s[left++]]++;
  }
  if (length <= s.size()) {
    return s.substr(minLeft, minRight - minLeft);
  }
  return "";
}

int main(int argc, char const *argv[]) {
  printf("%s", minWindow("a", "aa").c_str());
  return 0;
}
