#include <iostream>

using namespace std;

int main()
{
    double x, y;
    while(cin >> x >> y) {
        try {
            if (y == 0)
                throw runtime_error("the y should not be nil");
            cout << "x / y = " << x / y << endl;

        } catch (runtime_error err) {
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin|| c == 'n')
                break;
        }
    }
}
