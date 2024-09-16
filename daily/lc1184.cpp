#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
  int posCost = 0;
  int negaCost = 0;

  int pos = start;
  while (pos != destination) {
    posCost += distance[pos];
    pos = (pos + 1) % distance.size();
  }

  pos = start;
  while (pos != destination) {
    pos = (distance.size() + pos - 1) % distance.size();
    negaCost += distance[pos];
  }

  return min(negaCost, posCost);
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 2, 3, 4};
  printf("%d", distanceBetweenBusStops(input, 0, 1));
  return 0;
}
