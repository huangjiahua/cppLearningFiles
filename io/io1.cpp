#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    double x, y;
    cout << "multiplication of two floating point values" << endl;

    cout << "first operand:   ";
    if (!(cin >> x)) {
        cerr << "error while reading the first value"
             << endl;
        return EXIT_FAILURE;
    }

    cout << "second operand:  ";
    if (!(cin >> y)) {
        cerr << "error while reading the second value"
             << endl;
        return EXIT_FAILURE;
    }

    cout << x << " times " << y << " equals " << x * y << endl;
}
