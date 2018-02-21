#include <string>
#include <iostream>
#include <cctype>
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    string str = "hello, world";
    decltype(str.size()) n = 0;
    for( ; n < str.size(); n++)
        str[n] = 'X';
    cout << str << endl;

    return 0;
}
