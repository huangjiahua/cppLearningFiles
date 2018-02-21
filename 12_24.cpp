#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    char *ptr = new char[30];
    string input;
    while (cin >> input)
        strcat(ptr, input.c_str());
    cout << ptr << endl;

    delete[] ptr;
}
