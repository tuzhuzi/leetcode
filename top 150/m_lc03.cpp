#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 找出无重复字符的最大子串
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150
 */
int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> record;
  int maxLength = 0;
  int startIndex = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (record.find(c) != record.end()) {
      // 重复了，准备重新记录
      // 位置从c第一次出现的后一次开始记录
      startIndex = record[c] + 1;
      // 更新记录
      record.clear();
      for (int j = startIndex; j <= i; j++) {
        record[s[j]] = j;
      }
      continue;
    }
    record[c] = i;
    maxLength = max(maxLength, i - startIndex + 1);
  }
  return maxLength;
}

int lenghtOfLongestSubstring_better(string s) {
  int right = 0;
  int length = 0;
  unordered_set<char> record;
  for (int i = 0; i < s.size(); i++) {
    if (i > 0) {
      record.erase(s[i - 1]);
    }
    while (right < s.size() && !record.count(s[right])) {
      record.insert(s[right++]);
    }
    length = max(length, right - i);
  }
  return length;
}

int main(int argc, char const *argv[]) {
  printf("%d", lenghtOfLongestSubstring_better("pwwkew"));
  return 0;
}
