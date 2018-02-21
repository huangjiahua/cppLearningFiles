#include <iostream>
#include "HasPtr.h"

using namespace std;

int main()
{
    HasPtr h1("good morning");
    HasPtr h2("hello, my friend");
    swap(h1, h2);
    cout << h1.str() << "\n" << h2.str() << endl;
}
