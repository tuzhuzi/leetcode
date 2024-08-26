#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;

struct Employee {
  int id;
  int importance;
  vector<int> subordinates;
};

/**
 * https://leetcode.cn/problems/employee-importance/
 * 第一反应，应该用哈希表处理
 */
int getImportance(vector<Employee*> employees, int id) {
  unordered_map<int, Employee*> map;
  for (Employee* emp : employees) {
    map.insert(make_pair(emp->id, emp));
  }

  int importance = 0;
  queue<int> queue;
  queue.push(id);
  while (!queue.empty()) {
    int id = queue.front();
    queue.pop();
    auto it = map.find(id);
    if (it == map.end()) {
      continue;
    }
    importance += it->second->importance;
    // 题干确定了每名员工最多一名直系领导，否则这里还需要去重
    for (int subordiante : it->second->subordinates) {
      queue.push(subordiante);
    }
  }
  return importance;
}