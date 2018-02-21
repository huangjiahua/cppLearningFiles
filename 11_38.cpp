#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        ++word_count[word];
    }

    for (const auto &pr : word_count)
        cout << pr.first << " occurs " << pr.second
             << ((pr.second > 1) ? " times" : " time") << "." << endl;

}
