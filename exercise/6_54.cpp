#include <iostream>
#include <vector>

using namespace std;

using fc = int(*)(int, int);
vector<fc> vfc;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiple(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}


int main()
{
    vfc.push_back(add);
    vfc.push_back(subtract);
    vfc.push_back(multiple);
    vfc.push_back(divide);
    for(auto f : vfc)
        cout << f(10, 3) << endl;
    return 0;
}
