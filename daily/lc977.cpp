#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
  deque<int> negaQ;
  deque<int> posiQ;
  for (int num : nums) {
    if (num < 0) {
      negaQ.push_back(num * num);
    } else {
      posiQ.push_back(num * num);
    }
  }

  vector<int> output;
  while (!negaQ.empty() && !posiQ.empty()) {
    if (negaQ.back() < posiQ.front()) {
      output.push_back(negaQ.back());
      negaQ.pop_back();
    } else {
      output.push_back(posiQ.front());
      posiQ.pop_front();
    }
  }

  while (!negaQ.empty()) {
    output.push_back(negaQ.back());
    negaQ.pop_back();
  }
  while (!posiQ.empty()) {
    output.push_back(posiQ.front());
    posiQ.pop_front();
  }
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> output{-4, -2, -1, 0, 3, 5};
  for (int num : sortedSquares(output)) {
    printf("%d ", num);
  }
  return 0;
}
