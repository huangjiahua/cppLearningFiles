#include <iostream>

using namespace std;

void f() {cout << "f()" << endl;}
void f(int x) {cout << "f(int)" << endl;}
void f(int x, int y) {cout << "f(int, int)" << endl;}
void f(double x, double y = 3.14) {cout << "f(double, double = 3.14)" << endl;}

int main()
{
    f(2.56, 3.14);
}
