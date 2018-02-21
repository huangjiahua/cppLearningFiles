#include <iostream>

class A {
public:
    A() = default;
    virtual ~A() { }
};

class B : public A {
public:
    B() = default;
    ~B() override { }
};

class C : public B {
public:
    C() = default;
    ~C() override { }
};

class D : public B {
public:
    D() = default;
    ~D() override;
};

int main()
{
    A *pa = new A;
    A *pb = new B;
    A *pc = new C;

    std::cout << (typeid(A) == typeid(B)) << "\n"
              << (typeid(B) == typeid(C)) << std::endl;

}
