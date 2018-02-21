#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int sum = 0;
    int val;
    for (val = 50; val <= 100; val++)
        sum += val;
    cout << "The sum from 50 to 100 is "  << sum << endl;

    return 0;

}
