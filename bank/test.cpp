#include <iostream>
#include "bank.h"
using namespace std;

int main()
{
    Account a("102", "blue", 'T', 100);
    for (int i = 0; i < 65; ++i)
        cout << "=" << flush;
    cout << endl;
    cout.setf(std::ios::left);
    cout.width(20);
    cout << a.show_id();
    cout.setf(std::ios::left);
    cout.width(20);
    cout << a.show_name();
    cout.setf(std::ios::left);
    cout.width(20);
    cout << string{a.show_type()};
    cout.setf(std::ios::right);
    cout.width(5);
    cout << to_string(a.show_amount());
    return 0;

}
