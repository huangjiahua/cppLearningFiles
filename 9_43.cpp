#include <string>
#include <iostream>

using namespace std;

string replace_sub(string &s, const string &oldVal, const string &newVal)
{
    for (auto begin = s.begin();
        (s.end() - begin) >= (oldVal.end() - oldVal.begin()); ){
        if (string(begin, begin + oldVal.size()) == oldVal) {
            begin = s.erase(begin, begin + oldVal.size());
            begin = s.insert(begin, newVal.cbegin(), newVal.cend());
            begin += newVal.size();
        }
        else
            ++begin;
    }
    return s;
}


int main()
{
    string s = "tho you have a car. tho you are a tiger.";
    cout << replace_sub(s, "tho", "though") << endl;

}
