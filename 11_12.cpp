#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    string str;
    int i;
    vector<pair<string, int>> vp;
    while (cin >> str >> i) {
        vp.push_back(pair<string, int>(str, i));
    }

    for (const auto &p : vp)
        cout << p.first << " ----> " << p.second << endl;

    return 0;
}
