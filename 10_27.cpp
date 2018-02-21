#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> vs1{"these", "violent", "delights", "have", "violent",
                       "ends"};
    vector<string> vs2;
    sort(vs1.begin(), vs1.end());
    unique_copy(vs1.begin(), vs1.end(), back_inserter(vs2));
    for (const auto &v : vs2)
        cout << v << " ";

}
