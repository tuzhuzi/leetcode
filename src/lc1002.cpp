#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> commonChars(vector<string> &words)
{
    int minFreqRecord[26];
    fill(minFreqRecord, minFreqRecord + 26, INT_MAX);
    int tempRecord[26];

    for (string w : words)
    {
        fill(tempRecord, tempRecord + 26, 0);
        for (char c : w)
        {
            tempRecord[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            minFreqRecord[i] = min(tempRecord[i], minFreqRecord[i]);
        }
    }

    vector<string> output;
    for (int i = 0; i < 26; i++)
    {
        while (minFreqRecord[i]-- > 0)
        {
            output.push_back(string(1, 'a' + i));
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    vector<string> words;
    words.push_back("allocate");
    words.push_back("label");
    words.push_back("roller");
    for (string w : commonChars(words))
    {
        printf("%s ", w.c_str());
    }
    return 0;
}
