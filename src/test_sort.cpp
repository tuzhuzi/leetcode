#include <cstdio>

#include "../header/sort.h"

int main(int argc, char const *argv[]) {
  vector<int> input{9, 8, 7, 6, 4, 2, 3, 1};
  quickSort(input);
  for (int i : input) {
    printf("%d ", i);
  }
  return 0;
}
