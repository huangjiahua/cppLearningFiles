#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), use(new size_t(1)), i(0) { }
    HasPtr(const HasPtr &org):
        ps(new string(*org.ps)), use(org.use), i(org.i) { ++*use; }
    ~HasPtr()
    {
        if (--*use == 0) {
            delete ps;
            delete use;
        }

    }
    HasPtr& operator=(const HasPtr &org)
    {
        ++*org.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = org.ps;
        i = org.i;
        use = org.use;
        return *this;
    }
    string str()
    {
        return *ps;
    }
private:
    std::string *ps;
    size_t *use;
    int i;
};


inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
}
