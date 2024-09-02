#include <cstdio>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int maxConsecutiveAnswers(string& answerKey, int k) {
  deque<int> diffPos;
  int maxLength = 0;
  int startPos = 0;

  for (int i = 0; i < answerKey.size(); i++) {
    // 延长连续数组
    if (answerKey[i] == 'T') {
      maxLength = max(maxLength, i - startPos + 1);
      continue;
    }
    // 把i位置改为T, 更新连续数组长度
    if (diffPos.size() < k) {
      diffPos.push_back(i);
      maxLength = max(maxLength, i - startPos + 1);
      continue;
    }
    // 把第一个修改位置改回来， 重新计算
    diffPos.push_back(i);
    startPos = diffPos.front() + 1;
    diffPos.pop_front();
    maxLength = max(maxLength, i - startPos + 1);
  }

  startPos = 0;
  diffPos.clear();
  for (int i = 0; i < answerKey.size(); i++) {
    if (answerKey[i] == 'F') {
      maxLength = max(maxLength, i - startPos + 1);
      continue;
    }
    if (diffPos.size() < k) {
      diffPos.push_back(i);
      maxLength = max(maxLength, i - startPos + 1);
      continue;
    }
    diffPos.push_back(i);
    startPos = diffPos.front() + 1;
    diffPos.pop_front();
    maxLength = max(maxLength, i - startPos + 1);
  }
  return maxLength;
}

int main(int argc, char const* argv[]) {
  string input =
      "FFTFTTFTTTTTTTTTTFTTFFFTTTFTTFFFTTTTFTTFFFTFTFFTFFFTFTFFFFFFTTFFTFFFTFFT"
      "FTFFFFFTTTTFFTFFFTTFTFTFFFFF";
  printf("%d", maxConsecutiveAnswers(input, 48));
  return 0;
}
