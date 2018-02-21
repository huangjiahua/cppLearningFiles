#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    set<string> exclude  = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a"};

    string word;
    while (cin >> word) {
        for (auto iter = word.begin();
            iter != word.end(); ++iter) {
            *iter = tolower(*iter);
            if (ispunct(*iter))
                iter = word.erase(iter);
            if (iter == word.end())
                break;
        }
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }

    for (const pair<string, size_t> w : word_count)
        cout << w.first << " occurs " << w.second << " times." << endl;
}
