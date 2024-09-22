#include <cstdio>
#include <string>
#include <vector>

using namespace std;

/**
 * 文本左右对齐
 * https://leetcode.cn/problems/text-justification/?envType=study-plan-v2&envId=top-interview-150
 */
vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<vector<string>> splits;
  int curWidth = 0;
  vector<string> t;
  for (string w : words) {
    curWidth += w.size();
    if (curWidth <= maxWidth) {
      t.push_back(w);
      // 至少有一个空格
      curWidth += 1;
      continue;
    }
    splits.push_back(vector<string>(t));
    t.clear();
    t.push_back(w);
    curWidth = w.size() + 1;
  }
  // 把最后一个数组加进来
  splits.push_back(vector<string>(t));

  vector<string> output;
  for (int i = 0; i < splits.size(); i++) {
    auto list = splits[i];
    int spaceCount = 0;
    int totalSpace = 0;
    if (i != splits.size() - 1 || list.size() >= 2) {
      int wordsSize = 0;
      for (string s : list) {
        wordsSize += s.size();
      }
      totalSpace = maxWidth - wordsSize;
      spaceCount = (totalSpace / (list.size() - 1)) +
                   (totalSpace % (list.size() - 1) != 0);
    }
    string s;
    if (i != splits.size() - 1) {
      for (string w : list) {
        s.append(w);
        for (int i = 0; i < min(spaceCount, totalSpace); i++) {
          s.append("*");
        }
        totalSpace -= spaceCount;
      }
    } else {
      int wordWidth = 0;
      for (int i = 0; i < list.size(); i++) {
        s.append(list[i]);
        wordWidth += list[i].size();
        if (i < list.size() - 1) {
          s.append("*");
          wordWidth + 1;
        } else {
          for (wordWidth; wordWidth < maxWidth; wordWidth++) {
            s.append("*");
          }
        }
      }
    }
    output.push_back(s);
  }
  return output;
}

int main(int argc, char const* argv[]) {
  vector<string> input{"This",          "is", "an", "example", "of", "text",
                       "justification."};
  auto ouput = fullJustify(input, 16);
  for (string s : ouput) {
    printf("%s\n", s.c_str());
  }
  return 0;
}
