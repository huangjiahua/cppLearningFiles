#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int sum(int i1, int i2)
{
    auto f = [i1](int num) -> int {return i1 + num;};
    return f(i2);
}


int main()
{
    cout << sum(1, 2) << endl;
}
