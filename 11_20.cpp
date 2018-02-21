#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        auto preturn = word_count.insert({word, 1});
        if (!preturn.second)
            ++preturn.first->second;
    }

    for (const auto &p : word_count)
        cout << p.first << " occurs " << p.second << " times." << endl;

    return 0;
}
