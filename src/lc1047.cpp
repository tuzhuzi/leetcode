#include<stack>
#include <string>
using namespace std;

 string removeDuplicates(string s) {
    stack<char> outPut;
    for (char c : s) {
        if (outPut.empty()) {
            outPut.push(c);
            continue;
        }
        char last = outPut.top();
        if (last == c) {
            outPut.pop();
        } else {
            outPut.push(c);
        }
    }
    if (outPut.empty()) {
        return "";
    }
    int size = outPut.size();
    char words[size];
    for (int i = size - 1; i >= 0; i--) {
        words[i] = outPut.top();
        outPut.pop();
    }
    return string(words, words+size);
 }