#include <string>
#include <iostream>
#include <vector>

using namespace std;

string replace_sub(string &s, const string &oldVal, const string &newVal)
{
    for (string::size_type i = 0; i != s.size(); ++i) {
        if (s.substr(i, oldVal.size()) == oldVal) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size() - 1;
        }
    }
    return s;
}


int main()
{
    string s = "tho you have a car. tho you are a tiger.";
    cout << replace_sub(s, "tho", "though") << endl;
    vector<int> x;
    x.push_back(1);
    int i;

}
