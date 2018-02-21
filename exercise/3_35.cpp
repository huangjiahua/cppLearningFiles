#include <iostream>

using namespace std;
int main()
{
    int list[] = {1, 2, 3, 3, 123, 35};
    int *p = list;
    while(p != end(list))
        *p++ = 0;

    for (int i : list)
        cout << i << " ";

    return 0;
}
