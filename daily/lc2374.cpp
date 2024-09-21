#include <cstdio>
#include <vector>

using namespace std;

int edgeScore(vector<int>& edges) {
  vector<int> record(edges.size(), 0);
  int maxVal = 0;
  for (int i = 0; i < edges.size(); i++) {
    record[edges[i]] += i;
    if (record[edges[i]] > maxVal) {
      maxVal = record[edges[i]];
    }
  }
  for (int i = 0; i < record.size(); i++) {
    if (record[i] == maxVal) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 0, 0, 0, 0, 7, 7, 5};
  printf("%d", edgeScore(input));
  return 0;
}
