#include <iostream>
#include <string>

class NoDefault {
public:
    NoDefault(int i, int j): mem(j) { }
    int f() {return mem;}
private:
    int mem;
};

class C {
private:
    NoDefault cmem;
public:
    C(int i): cmem(i, i) { }
    int func() {return cmem.f();}
};

int main()
{
    C x(2);
    std::cout << x.func() << std::endl;
}
