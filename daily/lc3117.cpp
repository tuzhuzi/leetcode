#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array/?envType=daily-question&envId=2024-08-16
 *  第一眼应该用回溯法来做
 *  同时这里包含了很多的重复运算， 需要引入一个map记录重复运算的结果
 *  map设计： 一重索引位置，二重索引位运算结果， 三重索引最小和
 *  注意递归中，传引用比传拷贝有更好的性能
 */
int dfs(vector<int>& nums, vector<int>& andValues, int numIndex,
        int andValueIndex, int curVal,
        vector<unordered_map<int, int>>& record) {
  // 一个有效的结果
  if (andValueIndex == andValues.size() && numIndex == nums.size()) {
    return 0;
  }
  // 一个无效的结果
  if (andValueIndex == andValues.size() || numIndex == nums.size()) {
    return -1;
  }
  int key = numIndex * andValues.size() + andValueIndex;
  // 有记忆
  if (record[key].count(curVal)) {
    return record[key][curVal];
  }
  int updateVal = curVal & nums[numIndex];
  if (updateVal & andValues[andValueIndex] < andValues[andValueIndex]) {
    record[key][curVal] = -1;
    return -1;
  }
  // 分支，继续扩大当前数组匹配
  int res =
      dfs(nums, andValues, numIndex + 1, andValueIndex, updateVal, record);
  if (updateVal == andValues[andValueIndex]) {
    // 分支，找下一个数组
    int anoRes = dfs(nums, andValues, numIndex + 1, andValueIndex + 1,
                     __INT_MAX__, record);
    if (anoRes != -1) {
      anoRes += nums[numIndex];
    }
    if (res != -1 && anoRes != -1) {
      res = min(res, anoRes);
    } else {
      res = res == -1 ? anoRes : res;
    }
  }
  // 更新记忆
  record[key][curVal] = res;
  return res;
}
int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
  vector<unordered_map<int, int>> record(nums.size() * andValues.size());
  int res = dfs(nums, andValues, 0, 0, __INT_MAX__, record);
  return res;
}

int main(int argc, char const* argv[]) {
  vector<int> nums{4, 4};
  vector<int> andValues{4};
  printf("%d", minimumValueSum(nums, andValues));
  return 0;
}
