#include <iostream>

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    int f2() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
    int use_base() { return 1; }
};

struct Derived_from_Protected : public Prot_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;
    Base *p = &d1;
    p = &dd1;

}
