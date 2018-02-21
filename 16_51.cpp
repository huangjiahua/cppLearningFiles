#include <iostream>
#include <string>

using namespace std;

template <typename ... Args> void g(Args ... args)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;
}

int main()
{
    g(string("good"), 1, 1.3, 'c');
}
