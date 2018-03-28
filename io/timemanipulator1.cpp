#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
using namespace std;

int main()
{
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm* nowTM = localtime(&t);
    cout << put_time(nowTM, "data: %x\ntime: %X\n") << endl;

    tm date;
    cout << "new date: ";
    cin >> get_time(&date, "%x");
    if (!cin) {
        cerr << "invalid format read" << endl;
    }
}
