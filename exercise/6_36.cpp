#include <iostream>
#include <string>

using namespace std;

using str10 = string[10];
string arr10[10];

decltype(arr10) &func(decltype(arr10) &arr)
{
    for (size_t i = 0; i < 10; ++i)
        arr[i] = "hello";

    return arr;
}

int main()
{
    string arr[10];
    for (size_t i = 0; i != 10; ++i)
        cout << func(arr)[i] << endl;
    cout << arr[1] << endl;
}
