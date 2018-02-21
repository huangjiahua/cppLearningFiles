#include <iostream>
#include <string>

using namespace std;

string add(string s, const string &prefix, const string &suffix)
{
    s.insert(s.begin(), prefix.cbegin(), prefix.cend());
    s.append(suffix);
    return s;
}

int main()
{
    string s = "Huang Huaizhou";
    cout << add(s, "Mr.", "") << endl;

    return 0;
}
