#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

/**
 * 数位差异之和
 * 不能直接循环计算，而需要引入数据统计
 * 分别统计每一位上数字的出现数量
 */
long long sumDigitDifferences(vector<int>& nums) {
  long long sum = 0;
  while (nums[0] > 0) {
    vector<int> record(10, 0);
    for (int& n : nums) {
      record[n % 10]++;
      n /= 10;
    }
    long long tempSum = 0;
    for (int i = 0; i < record.size(); i++) {
      tempSum += (nums.size() - record[i]) * record[i];
    }
    sum += tempSum / 2;
  }
  return sum;
}

int main(int argc, char const* argv[]) {
  vector<int> input{824, 843, 837, 620, 836, 234, 276, 859};
  printf("%d", sumDigitDifferences(input));
  return 0;
}
