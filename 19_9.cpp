#include <iostream>
#include <typeinfo>
#include <string>
#include "../DataStructure/exp1/Polynomial.h"

using std::cout;
using std::endl;

int main()
{
    int i = 0;
    std::string s("");
    int arr[10];
    Polynomial p;
    Polynomial::OrderedList l;
    cout << typeid(i).name() << endl
         << typeid(s).name() << endl
         << typeid(arr).name() << endl
         << typeid(&arr[0]).name() << endl
         << typeid(p).name() << endl
         << typeid(l).name() << endl;

    return 0;
}
