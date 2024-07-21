#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  int index1 = 0;
  int index2 = 0;
  unordered_set<int> set;
  while (index1 < nums1.size() && index2 < nums2.size()) {
    if (nums1[index1] == nums2[index2]) {
      set.insert(nums1[index1]);
      index1++;
      index2++;
      continue;
    }
    while (index1 < nums1.size() && nums1[index1] < nums2[index2]) {
      index1++;
    }
    while (index2 < nums2.size() && index1 < nums1.size() &&
           nums2[index2] < nums1[index1]) {
      index2++;
    }
  }
  vector<int> out;
  for (int value : set) {
    out.push_back(value);
  }
  return out;
}