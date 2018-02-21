#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str, str2;
    getline(cin, str);

    for(auto c : str)
        if (!ispunct(c))
            str2 += c;

    cout << str2 << endl;
    return 0;

}
