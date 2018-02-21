#include <iostream>
#include <functional>
#include <map>
#include <string>

using namespace std;

struct Minus {
    int operator()(int i, int j) { return i - j; }
};

int multiply(int i, int j)
{
    return i * j;
}

int divide(int i, int j)
{
    return i / j;
}

int main()
{
    auto plus = [](int i, int j) { return i + j; };
    auto mod = [](int i, int j) { return i % j; };
    map<string, function<int(int, int)> > calc{
        {"+", plus},
        {"-", Minus()},
        {"*", multiply},
        {"/", divide},
        {"%", mod}
    };

    cout << calc["+"](1, 2) << endl;
    cout << calc["-"](3, 2) << endl;
    cout << calc["*"](5, 6) << endl;
    cout << calc["/"](10, 3) << endl;
    cout << calc["%"](100, 2) << endl;

    return 0;
}
