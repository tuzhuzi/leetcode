#include <vector>
using namespace std;

/**
 * https://leetcode.cn/problems/special-array-ii/
 * 思路是将特性表记录下来，通过求和取代异或运算
 */
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
  vector<int> xorlist(nums.size(), 1);
  for (int i = 1; i < nums.size(); i++) {
    // 如果奇偶相反，则值递增1，
    // list[i]和list[j]之间的差异就代表连续的奇偶不同有多少个
    if ((nums[i] ^ nums[i - 1]) & 1 == 1) {
      xorlist[i] = xorlist[i - 1] + 1;
    } else {
      xorlist[i] = xorlist[i - 1];
    }
  }

  vector<bool> ret;
  for (vector<int> query : queries) {
    int x = query[0];
    int y = query[1];
    ret.push_back((xorlist[y] - xorlist[x]) == (y - x));
  }
  return ret;
}