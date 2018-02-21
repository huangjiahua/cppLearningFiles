#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadString {
private:
    istream &is;
public:
    ReadString(istream &i = cin): is(i) { }
    string operator()()
    {
        string ret;
        if (getline(is, ret))
            return ret;
        else
            return string();
    }
};

int main()
{
    ReadString rs;
    string line;
    vector<string> vs;
    do {
        line = rs();
        vs.push_back(line);
    } while (cin);
    for (const auto &str : vs)
        cout << str << endl;

    return 0;
}
