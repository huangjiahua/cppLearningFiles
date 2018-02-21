#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Foo {
private:
    vector<int> vi;
public:
    Foo(): vi() { };
    Foo(const Foo &f): vi(f.vi) { }
    Foo sorted() &&
    {
        sort(vi.begin(), vi.end());
        return *this;
    }
    Foo sorted() const &
    {
        return Foo(*this).sorted();
    }
};

int main()
{
    return 0;
}
