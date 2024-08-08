#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isMapEmpty(unordered_map<string, map<string, int>>& map) {
  for (auto autoIt : map) {
    for (auto mapIt : autoIt.second) {
      if (mapIt.second > 0) {
        return false;
      }
    }
  }
  return true;
}
bool dfs(unordered_map<string, map<string, int>>& map, vector<string>& path) {
  if (isMapEmpty(map)) {
    return true;
  }
  string lastLoc = path[path.size() - 1];
  if (map[lastLoc].empty()) {
    return false;
  }
  for (auto& it : map[lastLoc]) {
    if (it.second > 0) {
      path.push_back(it.first);
      it.second--;
      if (dfs(map, path)) {
        return true;
      }
      it.second++;
      path.pop_back();
    }
  }
  return false;
}

// 欧拉通路的解法，深度搜索，每一次删除一条记录，当到达没有0通路节点时，逆序记录
// 因为欧拉通路中最多只有1个死胡同，而这个策略下，死胡同会优先入队
// 最后得到的就是 起点 ----回到起点 -- 死胡同
void dfs_hierholz(unordered_map<string, map<string, int>>& map, string loc,
                  vector<string>& path) {
  for (auto& it : map[loc]) {
    while (it.second > 0) {
      it.second--;
      dfs_hierholz(map, it.first, path);
    }
  }
  path.push_back(loc);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
  vector<string> path;
  sort(tickets.begin(), tickets.end());
  unordered_map<string, map<string, int>> map;
  for (auto vec : tickets) {
    map[vec[0]][vec[1]]++;
  }
  dfs_hierholz(map, "JFK", path);
  reverse(path.begin(), path.end());
  return path;
}

int main(int argc, char const* argv[]) {
  vector<vector<string>> input{
      {"EZE", "TIA"}, {"EZE", "HBA"}, {"AXA", "TIA"}, {"JFK", "AXA"},
      {"ANU", "JFK"}, {"ADL", "ANU"}, {"TIA", "AUA"}, {"ANU", "AUA"},
      {"ADL", "EZE"}, {"ADL", "EZE"}, {"EZE", "ADL"}, {"AXA", "EZE"},
      {"AUA", "AXA"}, {"JFK", "AXA"}, {"AXA", "AUA"}, {"AUA", "ADL"},
      {"ANU", "EZE"}, {"TIA", "ADL"}, {"EZE", "ANU"}, {"AUA", "ANU"}};
  vector<string> output = findItinerary(input);
  for (string s : output) {
    printf("%s ", s.c_str());
  }
  return 0;
}
