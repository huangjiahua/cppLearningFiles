#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    cout << words.size() << endl;
    auto end_unique = unique(words.begin(), words.end());
    for (vector<string>::iterator i = words.begin(); i != words.end();
        ++i)
        cout << *i << " ";

    cout << endl;
    cout << words.size() << endl;
    words.erase(end_unique, words.end());
}

int main()
{
    vector<string> vs{"the", "the", "a", "a", "b", "b"};
    elimDups(vs);
    for (auto i : vs)
        cout << i << " ";
}
