#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
  stack<char> stack;
  unordered_map<char, char> map;
  map.insert(make_pair('(', ')'));
  map.insert(make_pair('[', ']'));
  map.insert(make_pair('{', '}'));

  for (char c : s) {
    if (stack.empty()) {
      stack.push(c);
      continue;
    }
    char top = stack.top();
    auto it = map.find(top);
    if (it != map.end() && it->second == c) {
      stack.pop();
    } else {
      stack.push(c);
    }
  }
  return stack.empty();
}