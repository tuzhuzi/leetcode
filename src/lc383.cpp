#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void recordString(string input, vector<int>& record) {
  for (char c : input) {
    record[c - 'a']++;
  }
}

bool canConstruct(string ransomNote, string magazine) {
  vector<int> ransomRecord(26, 0);
  vector<int> magazineRecord(26, 0);
  recordString(ransomNote, ransomRecord);
  recordString(magazine, magazineRecord);
  for (int i = 0; i < 26; i++) {
    if (ransomRecord[i] > magazineRecord[i]) {
      return false;
    }
  }
  return true;
}