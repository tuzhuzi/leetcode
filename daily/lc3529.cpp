#include <cstdio>
#include <vector>

using namespace std;

/**
 * 喝药问题，看起来和炒股问题类似
 * https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/description/
 * 这样就需要维护两个临时变量dp_a，dp_b, 分别代表正在喝a, b时获取的能量
 * 演进方程有 dp_a[i] = max{dp_a[i - 1] + a[i], dp_b[i - 2] + a[i]}
 */
long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
  long long dp_a = energyDrinkA[0];
  // last_dp_a代表的是本轮发生切换，数值没有发生更改的情况，也就是dp_a[i - 2]
  long long last_dp_a = 0;
  long long dp_b = energyDrinkB[0];
  long long last_dp_b = 0;
  for (int i = 1; i < energyDrinkA.size(); i++) {
    long long t_a = dp_a;
    long long t_b = dp_b;
    dp_a = max(dp_a, last_dp_b) + energyDrinkA[i];
    dp_b = max(dp_b, last_dp_a) + energyDrinkB[i];
    last_dp_b = t_b;
    last_dp_a = t_a;
  }
  return max(dp_a, dp_b);
}

int main(int argc, char const* argv[]) {
  vector<int> energyA{4, 1, 1};
  vector<int> energyB{2, 1, 3};
  printf("%d", maxEnergyBoost(energyA, energyB));
  return 0;
}
