#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    int freqRecord[26];
    memset(freqRecord, 0, 26);
    for (char c : s)
    {
        freqRecord[c]++;
    }
    for (char c : t)
    {
        freqRecord[c]--;
        if (freqRecord[c] < 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s = "anagram";
    string t = "nagaram";
    printf("isAnagram %d", isAnagram(s, t));
    return 0;
}
