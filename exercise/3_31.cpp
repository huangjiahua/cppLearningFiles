#include <iostream>

using namespace std;

int main()
{
    int list[10];
    for (size_t i = 0; i < 10; i++)
        list[i] = i;

    for(int t : list)
        cout << t << " ";

    return 0;
}
