#include <cstdio>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int tempSum, int target, int& count,
         vector<int>& temp) {
  if (tempSum == target) {
    count++;
    for (int i : temp) {
      printf("%d", i);
    }
    printf("\n");
    return;
  }
  if (tempSum > target) {
    return;
  }
  for (int num : nums) {
    temp.push_back(num);
    dfs(nums, tempSum + num, target, count, temp);
    temp.pop_back();
  }
}

int combinationSum4(vector<int>& nums, int target) {
  vector<int> dp(target + 1, 0);
  dp[0] = 1;
  // 全排列组合的递归公式 dp[i] = sum(dp[i - num])
  // dp[i]是和为i的全排列， dp[i - m]相当m打头的全排列
  for (int i = 1; i <= target; i++) {
    for (int num : nums) {
      if (i >= num) {
        dp[i] += dp[i - num];
      }
    }
  }
  return dp[target];
}

int main(int argc, char const* argv[]) {
  vector<int> input{
      10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150,
      160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
      310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450,
      460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
      610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750,
      760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900,
      910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
  //   int count = 0;
  //   vector<int> temp;
  //   dfs(input, 0, 4, count, temp);
  printf("%d", combinationSum4(input, 999));
  return 0;
}
