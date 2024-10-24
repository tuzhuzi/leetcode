#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int findWinningPlayer(vector<int>& skills, int k) {
  // 最多就连续胜size - 1场
  if (k >= skills.size()) {
    k = skills.size() - 1;
  }
  int peak = 0;
  int i = 0;
  while (i < skills.size()) {
    peak = skills[i];
    int step = 1;
    // 最多要赢得数量，不是第一次那个循环的话， i已经赢得一次比较了，所以变成k-1
    int maxWinCount = i > 0 ? k - 1 : k;
    while (i + step < skills.size() && skills[i + step] < peak && step <= maxWinCount) {
      step++;
    } 
    // 如果循环到了队尾，或者step > k， 则符合跳出条件
    if (i + step >= skills.size() || step > maxWinCount) {
      break;
    }
    // 否则从新的peak开始循环
    i += step;
  }
  return i;
}

int main(int argc, char const *argv[])
{
  
  return 0;
}
