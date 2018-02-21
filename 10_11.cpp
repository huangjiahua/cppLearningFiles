#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(), isShorter);
}

void reOrder(vector<string> &words)
{
    sort(words.begin(), words.end(), isShorter);
}

int main()
{
    vector<string> vs{"the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"};
    elimDups(vs);

    for (const auto &v : vs)
        cout << v << " " << flush;

    cout << endl;
    

    return 0;
}
