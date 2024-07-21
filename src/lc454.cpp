#include <unordered_map>
#include <vector>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                 vector<int>& nums4) {
  unordered_map<int, int> abMap;
  for (int n1 : nums1) {
    for (int n2 : nums2) {
      int count = 0;
      int sum = n1 + n2;
      unordered_map<int, int>::iterator it = abMap.find(sum);
      if (it != abMap.end()) {
        count = it->second;
      }
      abMap.insert_or_assign(sum, count + 1);
    }
  }
  int count = 0;
  for (int n3 : nums3) {
    for (int n4 : nums4) {
      int sum = n3 + n4;
      unordered_map<int, int>::iterator it = abMap.find(-sum);
      if (it != abMap.end()) {
        count += it->second;
      }
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  vector<int> nums1 = {-1, -1};
  vector<int> nums2 = {-1, 1};
  vector<int> nums3 = {1, -1};
  vector<int> nums4 = {1, -1};
  printf("%d", fourSumCount(nums1, nums2, nums3, nums4));
  return 0;
}
