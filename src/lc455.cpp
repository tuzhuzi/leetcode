#include <algorithm>
#include <vector>

using namespace std;

/**
 * 贪心策略
 * 优先用尽量小的饼干满足胃口小的孩子，让尽量多的孩子都能吃饱
 */
int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  vector<bool> record(g.size(), false);
  int count = 0;
  // 记录一下饼干指针，不需要从头遍历
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    for (j; j < g.size(); j++) {
      if (g[j] >= s[i] && !record[j]) {
        record[j] = true;
        count++;
        break;
      }
    }
  }
  return count;
}