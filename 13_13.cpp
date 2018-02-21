#include <iostream>
#include <vector>

using namespace std;

struct X {
    X() {cout << "X()" << endl;}
    X(const X &) {cout << "X(const X &)" << endl;}
    X operator=(const X &) {cout << "X operator=(const X &)" << endl;
        return *this;}
    ~X() {cout << "~X()" << endl;}
};

X func(const X a, const X &b)
{
    cout << endl;
    return a;
}

int main()
{
    X a, b;
    b = a;


    /*
     * X()
     * X()
     * X operator=(const X &)
     * X(const X &)
     * X(const X &)
     * X()
     * X operator=(constX &)
     * X(const X &)
     * X(const X &)
     * X(const X &)
     * X(const X &)
     * ~X()
     * ~X()
     * ~X()
     * ~X()
     */
}
