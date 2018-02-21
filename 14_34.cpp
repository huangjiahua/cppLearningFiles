#include <iostream>

using namespace std;

struct IfThenElse {
    IfThenElse() { }
    int operator()(bool test, int ret1, int ret2)
    {
        if (test)
            return ret1;
        return ret2;
    }
};

int main()
{
    IfThenElse t;
    bool test = (3 > 1);
    int x = t(test, 1, 2);
    cout << x << endl;

}
