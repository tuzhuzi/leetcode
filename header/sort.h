#include <vector>
using namespace std;

void quickSort(vector<int>& list, int l, int r) {
  if (l >= r) {
    return;
  }
  int x = list[l];
  int left = l;
  int right = r;
  while (left < right) {
    while (right > left && list[right] >= x) {
      right--;
    }
    list[left] = list[right];
    while (left < right && list[left] <= x) {
      left++;
    }
    list[right] = list[left];
  }
  list[left] = x;
  quickSort(list, l, left - 1);
  quickSort(list, left + 1, r);
}

void quickSort(vector<int>& list) { quickSort(list, 0, list.size() - 1); }