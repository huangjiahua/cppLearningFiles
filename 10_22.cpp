#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check5(string s, string::size_type sz)
{
    return s.size() > sz;
}

int main()
{
    vector<string> vs{"these", "violent", "delights", "have",
        "violent", "ends"};
    cout << count_if(vs.begin(), vs.end(),
        bind(check5, _1, 5));
    cout << endl;
}
