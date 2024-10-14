#include <algorithm>
#include <vector>

using namespace std;

int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int count = 0;
  for (int i = 0; i < nums1.size(); i++) {
    for (int j = 0; j < nums2.size(); j++) {
      int v = k * nums2[j];
      if (v > nums1[i]) {
        break;
      }
      if (nums1[i] % v == 0) {
        count++;
      }
    }
  }
  return count;
}