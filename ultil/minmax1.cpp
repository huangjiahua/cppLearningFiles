#include <algorithm>
#include <iostream>
using namespace std;

bool int_ptr_less(int *a, int *b)
{
    return *a < *b;
}

int main()
{
    int x = 1;
    long y = 2;
    int z = max<int>(x, y);
    cout << z << endl;
}
