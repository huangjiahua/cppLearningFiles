#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkStr(string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> vs({"good", "morning", "my", "dear", "friend"});
    vector<string>::iterator iter = partition(vs.begin(), vs.end(), checkStr);
    for ( ; iter != vs.end(); ++iter)
        cout << *iter << " ";

    return 0;
}
