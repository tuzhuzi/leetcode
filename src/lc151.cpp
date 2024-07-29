#include <string>
#include <vector>
using namespace std;

vector<string> splitWords(string s) {
  vector<char> tempWords;
  vector<string> output;
  for (char c : s) {
    if (c == ' ') {
      if (!tempWords.empty()) {
        output.push_back(string(tempWords.begin(), tempWords.end()));
        tempWords.clear();
      }
    } else {
      tempWords.push_back(c);
    }
  }
  if (!tempWords.empty()) {
    output.push_back(string(tempWords.begin(), tempWords.end()));
  }
  return output;
}

string reverseWords(string s) {
  vector<string> splits = splitWords(s);
  string output;
  for (int i = splits.size() - 1; i >= 0; i--) {
    if (!output.empty()) {
      output.append(" ");
    }
    output.append(splits[i]);
  }
  return output;
}

void revertString(string& s, int& insertPosition, int start, int end) {
  // 先将words拷贝过去
  int tempStart = insertPosition;
  int tempEnd = end - start + insertPosition;
  for (int i = start; i <= end; i++) {
    s[insertPosition++] = s[i];
  }
  while (tempStart < tempEnd) {
    char c = s[tempStart];
    s[tempStart] = s[tempEnd];
    s[tempEnd] = c;
    tempStart++;
    tempEnd--;
  }
}

string revertWords_doublePointer(string& s) {
  int sIndex = -1;
  int eIndex = 0;
  int insertPosition = 0;
  while (eIndex < s.size()) {
    if (s[eIndex] == ' ' && sIndex >= 0 || eIndex == s.size() - 1) {
      revertString(s, insertPosition, sIndex, eIndex - 1);
      sIndex = -1;
      eIndex++;
      continue;
    }
    if (s[eIndex] != ' ' && sIndex < 0) {
      sIndex = eIndex;
    }
    eIndex++;
  }
  for (int i = insertPosition; i < s.size(); i++) {
    s[i] = ' ';
  }
  return s;
}

int main(int argc, char const* argv[]) {
  string input = "a good   example";
  printf("%s", revertWords_doublePointer(input).c_str());
  return 0;
}
