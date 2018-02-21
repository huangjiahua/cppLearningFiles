#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1, str2;
    cout << "Input the first string" << endl;
    getline(cin, str1);
    cout << "Input the second string" << endl;
    getline(cin, str2);


    if (str1.size() == str2.size())
        cout << '\n' << "These strings' length are equal" << endl;
    else if(str1.size() > str2.size())
        cout << '\n' << str1 << "\nis longer" << endl;
    else
        cout << '\n' << str2 << "\nis longer" << endl;

    return 0;
}
