#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
    string word;
    vector<string> words;
    while(cin >> word)
        words.push_back(word);
    for (auto itv = words.begin(); itv != words.end(); itv++)
        for (auto strv = itv->begin(); strv != itv->end(); strv++)
            *strv = toupper(*strv);

    for(auto itv = words.begin(); itv != words.end(); itv++)
        cout << *itv << " ";

    return 0;
}
