#include <iostream>
using namespace std;

int num = 0;


class numbered {
friend void f(numbered &s);
public:
    numbered(): mysn(num) { ++num; }
    numbered(const numbered &org): mysn(org.mysn + 1) { ++num; }
    numbered& operator=(const numbered &org)
    {
        mysn = org.mysn + 1;
        ++num;
        return *this;
    }
private:
    int mysn;
};

void f(numbered &s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    cout << num << endl;
}
