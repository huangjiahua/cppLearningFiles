#include <iostream>
#include <random>

using namespace std;

int random_number(int min, int max, int seed = 0)
{
    static uniform_int_distribution<int> d(min, max);
    default_random_engine e(seed);
    return d(e);
}

int main()
{
    cout << random_number(2, 7) << endl;
}
