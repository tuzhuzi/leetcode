#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
  sort(people.begin(), people.end(), [](auto a, auto b) {
    // 优先按高度排，按按要求的人数从小到大排
    // 先按高度排号， 意味着矮子再排序不会影响高个儿的顺序
    if (a[0] != b[0]) {
      return a[0] > b[0];
    }
    return a[1] < b[1];
  });
  for (int i = 0; i < people.size(); i++) {
    int insertIndx = 0;
    int count = 0;
    for (int j = 0; j < i; j++) {
      if (people[j][0] >= people[i][0]) {
        count++;
      }
      if (count == people[i][1]) {
        insertIndx = j + 1;
        break;
      }
    }
    if (insertIndx == i) {
      continue;
    }
    // 插入操作
    vector<int> temp = vector<int>(people[i]);
    for (int j = i; j > insertIndx; j--) {
      people[j][0] = people[j - 1][0];
      people[j][1] = people[j - 1][1];
    }
    people[insertIndx][0] = temp[0];
    people[insertIndx][1] = temp[1];
  }
  return people;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> input{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  auto output = reconstructQueue(input);
  for (auto vec : output) {
    printf("%d %d\n", vec[0], vec[1]);
  }
  return 0;
}
