#include <iostream>
#include <string>

using namespace std;

template<typename T, unsigned N>
void print(ostream &os, const T (&arr)[N])
{
    for (int i = 0; i < N; ++i)
        os << arr[i];
}

int main()
{
    char str[] = "good morning fucker!";
    print(cout, str);
    return 0;
}
