#include <cstdio>

int removeElement(int* nums, int numsSize, int val) {
  int sIndex = 0;
  int eIndex = 0;
  for (eIndex; eIndex < numsSize; eIndex++) {
    if (nums[eIndex] != val) {
      nums[sIndex++] = nums[eIndex];
    }
  }
  return sIndex;
}

int main(int argc, char const* argv[]) {
  int test[]{1, 2, 2, 3, 2, 3, 4, 2, 5};
  int count = removeElement(test, 9, 2);
  for (int i = 0; i < count; i++) {
    printf("%d ", test[i]);
  }
  return 0;
}
