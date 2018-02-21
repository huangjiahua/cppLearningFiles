#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> text;
    string input;
    while(getline(cin, input))
        text.push_back(input);

    for (auto it = text.begin();
         it != text.end() && !it->empty();
         ++it)
         for (auto &r : *it)
            r = toupper(r);

    for(auto c : text)
        cout << c << " ";

    return 0;
}
