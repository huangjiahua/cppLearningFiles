#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &org): ps(new string(*org.ps)), i(org.i) { }
    HasPtr& operator=(const HasPtr &org)
    {
        string* new_ps = new string(*org.ps);
        ps = new_ps;
        delete new_ps;
        i = org.i;
        return *this;
    }
private:
    std::string *ps;
    int i;
};
