#include <iostream>

using namespace std;

int main()
{
    int i = 0, *p = &i, &r = i;
    decltype(i) a = 3;
    cout << a << endl;
    decltype(*p + 9) b;
    decltype(r + 3) c = i;
}
