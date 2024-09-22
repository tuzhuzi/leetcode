#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

/**
 * 接雨水
 * https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150
 */

int clacVolum(vector<int>& height, int left, int right) {
  int h = min(height[left], height[right]);
  int volum = 0;
  for (int i = left; i <= right; i++) {
    volum += max(0, h - height[i]);
  }
  return volum;
}
int trap(vector<int>& height) {
  vector<int> peaks;
  for (int i = 0; i < height.size(); i++) {
    if (i > 0 && height[i] < height[i - 1]) {
      continue;
    }
    if (i < height.size() - 1 && height[i] < height[i + 1]) {
      continue;
    }
    peaks.push_back(i);
  }

  sort(peaks.begin(), peaks.end(),
       [&height](int i1, int i2) { return height[i1] > height[i2]; });
  int volum = 0;
  int left = min(peaks[0], peaks[1]);
  int right = max(peaks[0], peaks[1]);
  volum += clacVolum(height, left, right);
  for (int i = 2; i < peaks.size(); i++) {
    if (peaks[i] > right) {
      volum += clacVolum(height, right, peaks[i]);
      right = peaks[i];
      continue;
    }
    if (peaks[i] < left) {
      volum += clacVolum(height, peaks[i], left);
      left = peaks[i];
      continue;
    }
  }
  return volum;
}

int main(int argc, char const* argv[]) {
  vector<int> input{4, 2, 0, 3, 2, 5};
  printf("%d", trap(input));
  return 0;
}
