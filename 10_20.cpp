#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> vs{"these", "violent", "delights", "have",
        "violent", "ends"};
    cout << count_if(vs.begin(), vs.end(),
        [](string s) -> bool {if(s.size() > 5) return true; return false;});
    cout << endl;
}
