#include <cstdio>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
  if (source == target) {
    return 0;
  }
  // 路线和路线之间是否联通
  vector<vector<int>> edges(routes.size(), vector<int>(routes.size(), 0));
  // 从站点可换成的路线
  unordered_map<int, unordered_set<int>> map;
  for (int i = 0; i < routes.size(); i++) {
    for (int sta : routes[i]) {
      for (int j : map[sta]) {
        edges[i][j] = 1;
        edges[j][i] = 1;
      }
      map[sta].insert(i);
    }
  }

  // 线路距离
  vector<int> dis(routes.size(), -1);
  // bfs队列
  deque<int> q;
  for (int route : map[source]) {
    dis[route] = 1;
    q.push_back(route);
    if (map[target].find(route) != map[target].end()) {
      return dis[route];
    }
  }

  while (!q.empty()) {
    int curRoute = q.front();
    q.pop_front();
    for (int i = 0; i < routes.size(); i++) {
      if (edges[curRoute][i] == 1 && dis[i] == -1) {
        dis[i] = dis[curRoute] + 1;
        q.push_back(i);
        if (map[target].find(i) != map[target].end()) {
          return dis[i];
        }
      }
    }
  }
  return -1;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> routes{{1, 2, 7}, {3, 6, 7}};
  printf("%d", numBusesToDestination(routes, 1, 6));
  return 0;
}
