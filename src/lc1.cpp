#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> map;
  vector<int> outPut;
  for (int i = 0; i < nums.size(); i++) {
    unordered_map<int, int>::iterator it = map.find(target - nums[i]);
    if (it != map.end()) {
      outPut.push_back(it->second);
      outPut.push_back(i);
      break;
    }
    map.insert(make_pair(nums[i], i));
  }
  return outPut;
}