#include <iostream>
#include <vector>
#include <string>

using namespace std;

string alpha = ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
string num = ("0123456789");

int main(int argc, char *argv[])
{
    vector<string::size_type> al, nu;
    if (argc < 2)
        return 1;

    string to_find(argv[1]);

    string::size_type pos = 0;
    while ((pos = to_find.find_first_of(num, pos)) != string::npos) {
        nu.push_back(pos);
        ++pos;
    }

    pos = 0;
    while ((pos = to_find.find_first_of(alpha, pos)) != string::npos) {
        pos = to_find.find_first_of(alpha, pos);
        al.push_back(pos);
        ++pos;
    }

    cout << "ALPHA INDEX: ";
    for (const auto & i : al)
        cout << i << " " << flush;
    cout << endl;

    cout << "DIGIT INDEX: ";
    for (const auto & i : nu)
        cout << i << " " << flush;
    cout << endl;

    return 0;
}
