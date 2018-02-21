#include <chrono>
#include "clock.h"

using namespace std;

int main()
{
    cout << "system_clock  " << endl;
    printClockData<std::chrono::system_clock>();

    cout << "\nhigh_resolutino_clock: " << endl;
    printClockData<std::chrono::high_resolution_clock>();

    cout << "\nsteady_clock: " << endl;
    printClockData<std::chrono::steady_clock>();
}
