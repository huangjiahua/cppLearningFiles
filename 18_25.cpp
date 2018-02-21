#include <iostream>

using std::cout;
using std::endl;

class Base1 {
public:
    virtual void print() { cout << "Base1" << endl; }
    virtual ~Base1() { cout << "DB1" << endl; }
};

class Base2 {
public:
    virtual void print() { cout << "B2" << endl; }
    virtual ~Base2() { cout << "DB2" << endl; }
};

class D1: public Base1 {
public:
    int i = 3;
    void print() override { cout << "D1" << endl; }
    ~D1() { cout << "DD1" << endl; }
};

class D2: public Base2 {
public:
    int i = 1;
    void print() override { cout << "D2" << endl; }
    ~D2() { cout << "DD2" << endl; }
};

class MI: public D1, public D2 {
public:
    ~MI() { cout << "DMI" << endl;}
};

class B {
public:
    int i = 3;
};

class D: public B {
public:
    int i = 4;
};


int main()
{
    MI mi;
    mi.Base1::print();
}
