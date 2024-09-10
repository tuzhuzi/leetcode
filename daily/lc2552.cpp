#include <cstdio>
#include <vector>

using namespace std;

long long countQuadruplets(vector<int>& nums) {
  // 题目要求i < j < k <m, nums[i] < nums[k] < nums[j] < nums[m]
  // 解题思路是找到 j<k但nums[j] >
  // mums[k]的特殊数值对，然后加上j左侧比nums[k]小的和k右侧比nums[j]大的
  vector<vector<int>> rightBigger(nums.size() + 1,
                                  vector<int>(nums.size() + 1, 0));
  vector<vector<int>> leftLower(nums.size() + 1,
                                vector<int>(nums.size() + 1, 0));
  // 状态转移 rb[i][j] = rb[i+1][j] + nums[i + 1] > j?
  for (int j = nums.size(); j >= 1; j--) {
    for (int i = nums.size() - 1; i >= 0; i--) {
      rightBigger[i][j] = rightBigger[i + 1][j];
      // nums[i + 1 - 1]
      if (nums[i] > j) {
        rightBigger[i][j]++;
      }
    }
  }
  // ll[i][j] = ll[i - 1][j] + ll[i] < j
  for (int j = 1; j <= nums.size(); j++) {
    for (int i = 2; i <= nums.size(); i++) {
      leftLower[i][j] = leftLower[i - 1][j];
      // nums[i - 1 - 1]
      if (nums[i - 2] < j) {
        leftLower[i][j]++;
      }
    }
  }
  long long count = 0L;
  for (int i = 1; i < nums.size() - 1; i++) {
    for (int j = nums.size() - 1; j > i; j--) {
      if (nums[j] > nums[i]) {
        continue;
      }
      count += leftLower[i + 1][nums[j]] * rightBigger[j + 1][nums[i]];
    }
  }
  return count;
}

long long countQuadruplets_better(vector<int>& nums) {
  vector<int> pre(nums.size() + 1, 0);
  long long count = 0L;
  // 思路和上面是一样的
  for (int i = 1; i < nums.size() - 1; i++) {
    // auf 代表j-n之间， 大于nums[i]的数量，自行递增即可
    int auf = 0;
    // pre[x]代表0-i之间小于x的数量
    for (int x = nums[i - 1] + 1; x <= nums.size(); x++) {
      // 左侧增加了一个nums[i - 1]
      // i - 1 < x的情况则要加1
      pre[x]++;
    }
    for (int j = nums.size() - 1; j > i; j--) {
      if (nums[j] > nums[i]) {
        auf++;
      } else {
        count += auf * pre[nums[j]];
      }
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  vector<int> input{1, 3, 5, 2, 4};
  printf("%d", countQuadruplets_better(input));
  return 0;
}
