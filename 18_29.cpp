#include <iostream>

using std::cout;
using std::endl;

struct Class {
    Class() { cout << "Class" << endl; }
    virtual ~Class() { cout << "DClass" << endl; }
};

struct Base: public Class {
    int i = 0;
    Base() { cout << "Base" << endl; }
    Base(int n): i(n) { cout << "Base(int)" << endl; }
    ~Base() { cout << "DBase" << endl; }
};

struct D1: public Base {
    D1(int n): Base(n) { cout << "D1(int)" << endl; }
    D1() { cout << "D1" << endl; }
    ~D1() { cout << "DD1" << endl; }
};

struct D2: public Base {
    D2(int n): Base(n) { cout << "D2(int)" << endl; }
    D2() { cout << "D2" << endl; }
    ~D2() { cout << "DD2" << endl; }
};

struct MI: public D1, public D2 {
    MI(int i, int j):D1(i), D2(j) { cout << "MI(int, int)" << endl; }
    MI() { cout << "MI" << endl; }
    ~MI() { cout << "DMI" << endl; }
};

struct Final: public MI {
    Final() { cout << "Final" << endl; }
    ~Final() { cout << "DFinal" << endl; }
};

int main()
{
    MI m(1, 2);
    cout << endl;
    cout << m.D1::i << endl;
    cout << m.D2::i << endl; 

    return 0;
}
