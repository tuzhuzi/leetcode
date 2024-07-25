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

int main(int argc, char const *argv[]) {
  string input = "a good   example";
  printf("%s", reverseWords(input).c_str());
  return 0;
}
