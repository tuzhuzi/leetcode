#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> record;

vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> outPut;
  sort(nums.begin(), nums.end());

  for (int num : nums) {
    auto it = record.find(num);
    if (it == record.end()) {
      record.insert(make_pair(num, 1));
      outPut.push_back(num);
    } else {
      it->second = it->second + 1;
    }
  }
  sort(outPut.begin(), outPut.end(), [](int a, int b) {
    auto ita = record.find(a);
    auto itb = record.find(b);
    if (ita != record.end() && itb != record.end()) {
      return ita->second > itb->second;
    }
    return false;
  });
  return vector<int>(outPut.begin(), outPut.begin() + k);
}

int main(int argc, char const* argv[]) {
  vector<int> input({1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 6});
  vector<int> output = topKFrequent(input, 2);
  for (int num : output) {
    printf("%d ", num);
  }
  return 0;
}
